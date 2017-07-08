# SmartHome

```
  方案一：
    智能开关(单片机) wifi
    控制端  手机、平板等移动设备

方案二：
    智能开关(单片机)  射频RF  2.4G 433M
    智能家庭网关(arm) RF 2.4G 433M wifi
    物联网云服务器
    控制端 手机、平板等移动设备
    附加：视频监控,抓拍
```

### 1 root

#### 1.1 rom：
* boot.img  	    内核
* rootfs.ext2    文件系统
* ubootpak.bin   bootloader

#### 1.2 Steps：

##### 1.2.1 set minicom

```
  sudo minicom -s
```

##### 1.2.2 connect

*	usb
*	serial
*	power

##### 1.2.3 run minicom

```
	sudo minicom
```

##### 1.2.4 reboot Development Board

    press any key before countdownend

##### 1.2.5run fastboot at Development Board

```
  fastboot
```

##### 1.2.6 root Develoment Board from PC

```
	sudo fastboot flash ubootpak ./ubootpak.bin
	sudo fastboot flash boot ./boot.img
	sudo fastboot flash system ./rootfs.ext2
```

##### 1.2.7 set PATH in Development

```
set bootargs root=/dev/mmcblk0p2 lcd=wy070ml tp=gslx680-linux
set bootcmd "ext4load mmc 2:1 0x48000000 uImage;bootm 0x48000000"
sav
reset
```

# set nfs

```
	sudo vim /etc/exports
```

add follows

> /abc *(rw,no_root_squash,sync)

```
	sudo mkdir /abc
	sudo chmod 777 /abc
	sudo /etc/init.d/nfs-kernel-server restart
```

## test：

```
	sudo mount 127.0.0.1:/abc /mnt
	sudo umount /mnt
```

> The internet cloud servers yeelink
> [yeelink][]

[yeelink]:http://www.yeelink.net

yeelink作用
```
phone----->yeelink---->laptop
            |
            V
		    other computer
		    Home Gateway
		    sensor
```
>	can connect some devices at one account
>
>	device：memory
>
>	[---------------------------]
>
>	one device can connect some sensors
>
>	sensor：memory
>
>	device and sensor
>
>	uplooking [t1|t2|t3|t4|t5|t6]
>
> at yeelink servece one device or one sensor means one ID
>
>when send / get data to yeelink should pay attention to this IDs:
> 1. API-key  user
> 2. 设备ID    devices
> 3. 传感器ID  sensor

# QT multithreaded programming
>	1. QT 默认有一个线程，叫做主线程/UI线程 \
>         UI的作用是绘制图形界面 \
>       	所以在UI线程中不能睡眠，不能阻塞，不能死循环

>	采集数据(有可能阻塞)------>界面显示 \
>	新线程------信号与槽------>UI线程 \

>	w------>方法运行在主线程--->显示数据(根据开关状态设置label) \
>		信号与槽 \
>	gssfs-->方法运行在新线程--->采集数据(获取开关状态)\


>	实例：通过手机控制QT程序
>	      QT程序把温湿度传送到服务器，手机查看

## Cross Compiling：

### 1. C code:
```
arm-linux-*
```
### 2. install compiler：
```
		tar -xvf arm-linux-gcc-4.5.1.tar.bz2
		cd 4.5.1/bin/
		pwd
```
> copy path add to $PATH
```
		vim ~/.bashrc
```
> add follow as \
> PATH=/home/zyli/s5p6818sdk_lzy1/package/4.5.1/bin:$PATH

>	if we open terminal before add $PATH,we need to
```
source ~/.bashrc
```

> test
```
		touch hello.c
		arm-linux-gcc hello.c -o hello
		file hello
```

## 3. QT code
```
		qmake make
		sudo mkdir /home/zyli/
		sudo chown uplooking:uplooking /home/zyli
		mkdir /home/zyli/s5p6818sdk_lzy1/Linux/src/buildroot/output -p
		tar -xvf host.tar.bz2 -C /home/zyli/s5p6818sdk_lzy1/Linux/src/buildroot/output
```
>	Test
```
		/home/zyli/s5p6818sdk_lzy1/Linux/src/buildroot/output/host/usr/bin/qmake -v
```
> QTCreator create a project (/home/zyli/bhht/armqt)
```
		cd /home/zyli/bhht/armqt
		/home/zyli/s5p6818sdk_lzy1/Linux/src/buildroot/output/host/usr/bin/qmake
		make
		file armqt
```

>ways to copy programe to board
>* tftp
>* nfs
>* ftp
>* uart
>
>	> use serial
>	>1. 配置文件路径
> >
> > ```
> >sudo minicom -s
>	>    ->Filenames and paths
> >            ->B - Upload directory   : /home/zyli/bhht
>	>   ->Save setup as dfl
> >```
>	2. entry in board terminal
>
> start the board
>```
>sudo minicom
>```
> 3. download file
>```
>	ctrl+a--->s
>	 ->zmodem
>	[Goto] choice the directory
>	[Okay] choice the file
> ```

## nfs

	1. set PC IP
	  add profile bhht:IP=192.168.2.5 24
	  if you want to connect to board use bhht
	2. check IP
	  ifconfig
	3. open nfs server
	4. set board IP
	  ifconfig eth0 192.168.2.6
	  ping 192.168.2.5
	5. bord mount PC sharing directory
	   mount -t nfs -o nolock,rw 192.168.2.5:/abc /mnt
	6. copy files  you want to share to /abc
	   cp <path>/armqt <path>/hello /abc
	7. use sharefile(just example)
	   /mnt/hello
	   /mnt/armqt
	8. umount
	   umount /mnt

## led & buzzer on/off:
  shell operation:
### buzzer:
```
echo 1 > /sys/devices/platform/x6818-beep/state
echo 0 > /sys/devices/platform/x6818-beep/state
```
### leds:
```
echo 1 > /sys/devices/platform/leds-gpio/leds/led1/brightess
echo 0 > /sys/devices/platform/leds-gpio/leds/led1/brightess
```

#### smartPhone to control board
> arm << libyeelink_lzy.so
```
 arm-linux-g++ ledyeelink.cpp -o ledyeelink -L ./ -lyeelink_lzy
```
> -L set the dirctery
>
>-l set the name of lld

> copy libyeelink_lzy.so to board's /bin

run shell at borad:

```
mount -t nfs -o nolock,rw 192.168.100.53:/abc /mnt/
cp /mnt/ledyeelink /bin/
cp /mnt/libyeelink_lzy.so  /lib

ifconfig
```
> dhcp get IP (board should be able to internet)
```
 /etc/init.d/S40network restart
```
> rum app use smartphone to control led
```
./ledyeelink
```

# Web code
## some errors in qt5 :

```
qt.network.ssl: QSslSocket: cannot resolve ASN1_INTEGER_get
qt.network.ssl: QSslSocket: cannot resolve ASN1_STRING_data
qt.network.ssl: QSslSocket: cannot resolve ASN1_STRING_length
qt.network.ssl: QSslSocket: cannot resolve ASN1_STRING_to_UTF8
qt.network.ssl: QSslSocket: cannot resolve BIO_ctrl
qt.network.ssl: QSslSocket: cannot resolve BIO_free
qt.network.ssl: QSslSocket: cannot resolve BIO_new
qt.network.ssl: QSslSocket: cannot resolve BIO_new_mem_buf
qt.network.ssl: QSslSocket: cannot resolve BIO_read
qt.network.ssl: QSslSocket: cannot resolve BIO_s_mem
qt.network.ssl: QSslSocket: cannot resolve BIO_write
qt.network.ssl: QSslSocket: cannot resolve EC_KEY_get0_group
qt.network.ssl: QSslSocket: cannot resolve EC_GROUP_get_degree
qt.network.ssl: QSslSocket: cannot resolve BN_num_bits
qt.network.ssl: QSslSocket: cannot resolve BN_mod_word
qt.network.ssl: QSslSocket: cannot resolve CRYPTO_free
qt.network.ssl: QSslSocket: cannot resolve CRYPTO_num_locks
qt.network.ssl: QSslSocket: cannot resolve CRYPTO_set_id_callback
qt.network.ssl: QSslSocket: cannot resolve CRYPTO_set_locking_callback
qt.network.ssl: QSslSocket: cannot resolve DSA_new
qt.network.ssl: QSslSocket: cannot resolve DSA_free
qt.network.ssl: QSslSocket: cannot resolve ERR_error_string
qt.network.ssl: QSslSocket: cannot resolve ERR_get_error
qt.network.ssl: QSslSocket: cannot resolve ERR_free_strings
qt.network.ssl: QSslSocket: cannot resolve EVP_CIPHER_CTX_cleanup
qt.network.ssl: QSslSocket: cannot resolve EVP_CIPHER_CTX_init
qt.network.ssl: QSslSocket: cannot resolve EVP_CIPHER_CTX_ctrl
qt.network.ssl: QSslSocket: cannot resolve EVP_CIPHER_CTX_set_key_length
qt.network.ssl: QSslSocket: cannot resolve EVP_CipherInit
qt.network.ssl: QSslSocket: cannot resolve EVP_CipherUpdate
qt.network.ssl: QSslSocket: cannot resolve EVP_CipherFinal
qt.network.ssl: QSslSocket: cannot resolve EVP_des_cbc
qt.network.ssl: QSslSocket: cannot resolve EVP_des_ede3_cbc
qt.network.ssl: QSslSocket: cannot resolve EVP_rc2_cbc
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_assign
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_set1_RSA
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_set1_DSA
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_set1_EC_KEY
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_free
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_get1_DSA
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_get1_RSA
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_get1_EC_KEY
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_new
qt.network.ssl: QSslSocket: cannot resolve EVP_PKEY_type
qt.network.ssl: QSslSocket: cannot resolve OBJ_nid2sn
qt.network.ssl: QSslSocket: cannot resolve OBJ_nid2ln
qt.network.ssl: QSslSocket: cannot resolve OBJ_sn2nid
qt.network.ssl: QSslSocket: cannot resolve OBJ_ln2nid
qt.network.ssl: QSslSocket: cannot resolve i2t_ASN1_OBJECT
qt.network.ssl: QSslSocket: cannot resolve OBJ_obj2txt
qt.network.ssl: QSslSocket: cannot resolve OBJ_obj2nid
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_PrivateKey
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_DSAPrivateKey
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_RSAPrivateKey
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_ECPrivateKey
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_DHparams
qt.network.ssl: QSslSocket: cannot resolve PEM_write_bio_DSAPrivateKey
qt.network.ssl: QSslSocket: cannot resolve PEM_write_bio_RSAPrivateKey
qt.network.ssl: QSslSocket: cannot resolve PEM_write_bio_ECPrivateKey
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_PUBKEY
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_DSA_PUBKEY
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_RSA_PUBKEY
qt.network.ssl: QSslSocket: cannot resolve PEM_read_bio_EC_PUBKEY
qt.network.ssl: QSslSocket: cannot resolve PEM_write_bio_DSA_PUBKEY
qt.network.ssl: QSslSocket: cannot resolve PEM_write_bio_RSA_PUBKEY
qt.network.ssl: QSslSocket: cannot resolve PEM_write_bio_EC_PUBKEY
qt.network.ssl: QSslSocket: cannot resolve RAND_seed
qt.network.ssl: QSslSocket: cannot resolve RAND_status
qt.network.ssl: QSslSocket: cannot resolve RSA_new
qt.network.ssl: QSslSocket: cannot resolve RSA_free
qt.network.ssl: QSslSocket: cannot resolve sk_new_null
qt.network.ssl: QSslSocket: cannot resolve sk_push
qt.network.ssl: QSslSocket: cannot resolve sk_free
qt.network.ssl: QSslSocket: cannot resolve sk_num
qt.network.ssl: QSslSocket: cannot resolve sk_pop_free
qt.network.ssl: QSslSocket: cannot resolve sk_value
qt.network.ssl: QSslSocket: cannot resolve SSL_CIPHER_description
qt.network.ssl: QSslSocket: cannot resolve SSL_CIPHER_get_bits
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_check_private_key
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_ctrl
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_free
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_new
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_set_cipher_list
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_set_default_verify_paths
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_set_verify
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_set_verify_depth
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_use_certificate
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_use_certificate_file
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_use_PrivateKey
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_use_RSAPrivateKey
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_use_PrivateKey_file
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_get_cert_store
qt.network.ssl: QSslSocket: cannot resolve SSL_accept
qt.network.ssl: QSslSocket: cannot resolve SSL_clear
qt.network.ssl: QSslSocket: cannot resolve SSL_connect
qt.network.ssl: QSslSocket: cannot resolve SSL_free
qt.network.ssl: QSslSocket: cannot resolve SSL_get_ciphers
qt.network.ssl: QSslSocket: cannot resolve SSL_get_current_cipher
qt.network.ssl: QSslSocket: cannot resolve SSL_version
qt.network.ssl: QSslSocket: cannot resolve SSL_get_error
qt.network.ssl: QSslSocket: cannot resolve SSL_get_peer_cert_chain
qt.network.ssl: QSslSocket: cannot resolve SSL_get_peer_certificate
qt.network.ssl: QSslSocket: cannot resolve SSL_get_verify_result
qt.network.ssl: QSslSocket: cannot resolve SSL_library_init
qt.network.ssl: QSslSocket: cannot resolve SSL_load_error_strings
qt.network.ssl: QSslSocket: cannot resolve SSL_new
qt.network.ssl: QSslSocket: cannot resolve SSL_ctrl
qt.network.ssl: QSslSocket: cannot resolve SSL_read
qt.network.ssl: QSslSocket: cannot resolve SSL_set_accept_state
qt.network.ssl: QSslSocket: cannot resolve SSL_set_bio
qt.network.ssl: QSslSocket: cannot resolve SSL_set_connect_state
qt.network.ssl: QSslSocket: cannot resolve SSL_shutdown
qt.network.ssl: QSslSocket: cannot resolve SSL_set_session
qt.network.ssl: QSslSocket: cannot resolve SSL_SESSION_free
qt.network.ssl: QSslSocket: cannot resolve SSL_get1_session
qt.network.ssl: QSslSocket: cannot resolve SSL_get_session
qt.network.ssl: QSslSocket: cannot resolve SSL_get_ex_new_index
qt.network.ssl: QSslSocket: cannot resolve SSL_set_ex_data
qt.network.ssl: QSslSocket: cannot resolve SSL_get_ex_data
qt.network.ssl: QSslSocket: cannot resolve SSL_set_psk_client_callback
qt.network.ssl: QSslSocket: cannot resolve SSL_set_psk_server_callback
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_use_psk_identity_hint
qt.network.ssl: QSslSocket: cannot resolve SSL_write
qt.network.ssl: QSslSocket: cannot resolve SSLv2_client_method
qt.network.ssl: QSslSocket: cannot resolve SSLv3_client_method
qt.network.ssl: QSslSocket: cannot resolve SSLv23_client_method
qt.network.ssl: QSslSocket: cannot resolve TLSv1_client_method
qt.network.ssl: QSslSocket: cannot resolve TLSv1_1_client_method
qt.network.ssl: QSslSocket: cannot resolve TLSv1_2_client_method
qt.network.ssl: QSslSocket: cannot resolve SSLv2_server_method
qt.network.ssl: QSslSocket: cannot resolve SSLv3_server_method
qt.network.ssl: QSslSocket: cannot resolve SSLv23_server_method
qt.network.ssl: QSslSocket: cannot resolve TLSv1_server_method
qt.network.ssl: QSslSocket: cannot resolve TLSv1_1_server_method
qt.network.ssl: QSslSocket: cannot resolve TLSv1_2_server_method
qt.network.ssl: QSslSocket: cannot resolve X509_NAME_entry_count
qt.network.ssl: QSslSocket: cannot resolve X509_NAME_get_entry
qt.network.ssl: QSslSocket: cannot resolve X509_NAME_ENTRY_get_data
qt.network.ssl: QSslSocket: cannot resolve X509_NAME_ENTRY_get_object
qt.network.ssl: QSslSocket: cannot resolve X509_PUBKEY_get
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_free
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_new
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_add_cert
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_free
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_init
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_new
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_set_purpose
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_get_error
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_get_error_depth
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_get_current_cert
qt.network.ssl: QSslSocket: cannot resolve X509_STORE_CTX_get_chain
qt.network.ssl: QSslSocket: cannot resolve X509_cmp
qt.network.ssl: QSslSocket: cannot resolve X509_dup
qt.network.ssl: QSslSocket: cannot resolve X509_print
qt.network.ssl: QSslSocket: cannot resolve X509_EXTENSION_get_object
qt.network.ssl: QSslSocket: cannot resolve X509_free
qt.network.ssl: QSslSocket: cannot resolve X509_get_ext
qt.network.ssl: QSslSocket: cannot resolve X509_get_ext_count
qt.network.ssl: QSslSocket: cannot resolve X509_get_ext_d2i
qt.network.ssl: QSslSocket: cannot resolve X509V3_EXT_get
qt.network.ssl: QSslSocket: cannot resolve X509V3_EXT_d2i
qt.network.ssl: QSslSocket: cannot resolve X509_EXTENSION_get_critical
qt.network.ssl: QSslSocket: cannot resolve X509_EXTENSION_get_data
qt.network.ssl: QSslSocket: cannot resolve BASIC_CONSTRAINTS_free
qt.network.ssl: QSslSocket: cannot resolve AUTHORITY_KEYID_free
qt.network.ssl: QSslSocket: cannot resolve ASN1_STRING_print
qt.network.ssl: QSslSocket: cannot resolve X509_check_issued
qt.network.ssl: QSslSocket: cannot resolve X509_get_issuer_name
qt.network.ssl: QSslSocket: cannot resolve X509_get_subject_name
qt.network.ssl: QSslSocket: cannot resolve X509_verify_cert
qt.network.ssl: QSslSocket: cannot resolve d2i_X509
qt.network.ssl: QSslSocket: cannot resolve i2d_X509
qt.network.ssl: QSslSocket: cannot resolve OPENSSL_add_all_algorithms_noconf
qt.network.ssl: QSslSocket: cannot resolve OPENSSL_add_all_algorithms_conf
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_load_verify_locations
qt.network.ssl: QSslSocket: cannot resolve SSLeay
qt.network.ssl: QSslSocket: cannot resolve SSLeay_version
qt.network.ssl: QSslSocket: cannot resolve i2d_SSL_SESSION
qt.network.ssl: QSslSocket: cannot resolve d2i_SSL_SESSION
qt.network.ssl: QSslSocket: cannot resolve SSL_select_next_proto
qt.network.ssl: QSslSocket: cannot resolve SSL_CTX_set_next_proto_select_cb
qt.network.ssl: QSslSocket: cannot resolve SSL_get0_next_proto_negotiated
qt.network.ssl: QSslSocket: cannot resolve DH_new
qt.network.ssl: QSslSocket: cannot resolve DH_free
qt.network.ssl: QSslSocket: cannot resolve d2i_DHparams
qt.network.ssl: QSslSocket: cannot resolve i2d_DHparams
qt.network.ssl: QSslSocket: cannot resolve DH_check
qt.network.ssl: QSslSocket: cannot resolve BN_bin2bn
qt.network.ssl: QSslSocket: cannot resolve EC_KEY_dup
qt.network.ssl: QSslSocket: cannot resolve EC_KEY_new_by_curve_name
qt.network.ssl: QSslSocket: cannot resolve EC_KEY_free
qt.network.ssl: QSslSocket: cannot resolve EC_get_builtin_curves
qt.network.ssl: QSslSocket: cannot resolve PKCS12_parse
qt.network.ssl: QSslSocket: cannot resolve d2i_PKCS12_bio
qt.network.ssl: QSslSocket: cannot resolve PKCS12_free
qt.network.ssl: Incompatible version of OpenSSL
```
> in some linux forbined opensslv2 due to security

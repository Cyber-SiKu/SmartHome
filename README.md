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

[yeelink]:www.yeelink.net

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

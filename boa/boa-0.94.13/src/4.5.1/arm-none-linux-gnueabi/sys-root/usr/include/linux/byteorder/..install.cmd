cmd_/opt/FriendlyARM/toolschain/4.5.1/arm-none-linux-gnueabi/sys-root/usr/include/linux/byteorder/.install := perl /work/toolchain/build/src/linux-2.6.35.4/scripts/headers_install.pl /work/toolchain/build/src/linux-2.6.35.4/include/linux/byteorder /opt/FriendlyARM/toolschain/4.5.1/arm-none-linux-gnueabi/sys-root/usr/include/linux/byteorder arm big_endian.h little_endian.h; perl /work/toolchain/build/src/linux-2.6.35.4/scripts/headers_install.pl /work/toolchain/build/arm-none-linux-gnueabi/build/build-kernel-headers/include/linux/byteorder /opt/FriendlyARM/toolschain/4.5.1/arm-none-linux-gnueabi/sys-root/usr/include/linux/byteorder arm ; touch /opt/FriendlyARM/toolschain/4.5.1/arm-none-linux-gnueabi/sys-root/usr/include/linux/byteorder/.install

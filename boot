set bootargs root=/dev/mmcblk0p2 lcd=wy070ml tp=gslx680-linux

set bootcmd "ext4load mmc 2:1 0x48000000 uImage;bootm 0x48000000"

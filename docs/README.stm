stm32mp157c EV1 or DK2 instructions
-----------------------------------

Firmware boots from an SD card. While rootfs and ESP partition
are on a USB stick.

1. Prepare SD with:
zcat ts-firmware-stm32mp157c-<ev1|dk2>.wic.gz > /dev/sdX

2. Prepere USB stick with:
zcat rootfs.wic.gz > /dev/sdUSB
You can use LEDGE RP for example:
http://snapshots.linaro.org/components/ledge/oe/ledge-multi-armv7/1265/rpb/ledge-qemuarm/ledge-gateway-ledge-qemuarm-20220218053618.rootfs.wic.gz

Note: if you used USB stick in other machine with current firmware before booting delete ubootefi.var file for ESP (first one) partition.

3. Plug both USB stick and SD card into the board. Power it on and trap it in the U-boot command line.

4. Add kernel board specific kernel parameters and EFI boot order.
efidebug boot add -b 1 BootLedge usb 0:1 efi/boot/bootarm.efi -i usb 0:1 ledge-initramfs.rootfs.cpio.gz -s 'console=ttySTM0,115200 console=tty0 root=UUID=6091b3a4-ce08-3020-93a6-f755a22ef03b rootwait panic=60'
efidebug boot order 1

5. Power cycle board it and it has to boot automatically now.

KV 260 AI starter kit 
---------------------

Firmware boots from an QSPI NOR. While rootfs and ESP partition
are on a USB stick.

1. Prepare QSPI
Keep FWUEN pressed and reset the board. 
Navigate to 192.168.0.111 on your browser and update Image A/B with the binaries
found in build/tmp/deploy/images/kv260/Image(A|B).bin

2. Prepere USB stick with:
zcat rootfs.wic.gz > /dev/sdUSB
You can use LEDGE RP for example:
http://snapshots.linaro.org/components/ledge/oe/ledge-multi-armv8/1254/rpb/ledge-qemuarm64/ledge-iot-ledge-qemuarm64-20220206235911.rootfs.wic.gz

Note: if you used USB stick in other machine with current firmware before booting delete ubootefi.var file for ESP (first one) partition.

3. Plug both USB stick and SD card into the board. Power it on and trap it in the U-boot command line.

4. Add kernel board specific kernel parameters and EFI boot order.
efidebug boot add -b 1 BootLedge usb 0:1 efi/boot/bootaa64.efi -i usb 0:1 ledge-initramfs.rootfs.cpio.gz -s 'console=ttyPS1,115200 console=tty0 root=UUID=6091b3a4-ce08-3020-93a6-f755a22ef03b rootwait panic=60'

or for mmc booting
efidebug boot add -b 1 BootLedge mmc 1:1 efi/boot/bootaa64.efi -i mmc 1:1 ledge-initramfs.rootfs.cpio.gz -s 'console=ttyPS1,115200 console=tty0 root=UUID=6091b3a4-ce08-3020-93a6-f755a22ef03b rootwait panic=60'
efidebug boot order 1

5. Power cycle board it and it has to boot automatically now.

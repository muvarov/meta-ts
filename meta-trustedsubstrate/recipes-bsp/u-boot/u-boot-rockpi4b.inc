# Generate Rockchip style loader binaries
inherit deploy

SRCREV = "734ad933766f0dbbeafe1b27211686940a5e6d16"

SRC_URI:append = " file://rockpi4b_defconfig"
COMPATIBLE_MACHINE = "rockpi4b"

DEPENDS += "trusted-firmware-a"

do_compile:prepend() {
	export BL31="${RECIPE_SYSROOT}/firmware/bl31.elf"
	ls -l ${BL31}
}

do_deploy:append() {
	mkdir -p ${DEPLOYDIR}
	cp ${B}/rockpi4b_defconfig/idbloader.img  ${DEPLOYDIR}/idbloader.img
	cp ${B}/rockpi4b_defconfig/u-boot.itb ${DEPLOYDIR}/u-boot.itb
	cp ${B}/rockpi4b_defconfig/arch/arm/dts/rk3399-rock-pi-4b.dtb ${DEPLOYDIR}/rk3399-rock-pi-4b.dtb

	cat > ${DEPLOYDIR}/README.flash << EOF
	  - Write prefixed SPL at 64th sector
    	  => sudo dd if=idblock.img of=/dev/sdc seek=64

  	  - Write U-Boot proper at 16384 sector
   	  => sudo dd if=u-boot.itb of=/dev/sdc seek=16384
    	  => sync
EOF
}

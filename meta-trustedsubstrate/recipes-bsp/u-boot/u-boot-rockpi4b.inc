# Generate Rockchip style loader binaries

DEPENDS += "trusted-firmware-a"

do_compile:prepend() {
	export BL31="${RECIPE_SYSROOT}/firmware/bl31.elf"
	ls -l ${BL31}
}

do_install:append() {
	mkdir -p ${DEPLOYDIR}
	install idbloader.img  ${DEPLOYDIR}/idbloader.img
	install u-boot.itb ${DEPLOYDIR}/u-boot-${PV}.img

	cat > ${DEPLOYDIR}/README.flash << EOF
	  - Write prefixed SPL at 64th sector
    	  => sudo dd if=idblock.img of=/dev/sdc seek=64

  	  - Write U-Boot proper at 16384 sector
   	  => sudo dd if=u-boot.itb of=/dev/sdc seek=16384
    	  => sync
EOF
}

# Generate Rockchip style loader binaries
inherit deploy

SRCREV = "4e81f3be340072ad2c0aac093677333702f14f22"

SRC_URI:append = " file://rockpi4b_defconfig"
SRC_URI:append = " file://0004-phy-rockchip-inno-usb2-fix-hang-when-multiple-controllers-exit.patch"
COMPATIBLE_MACHINE = "rockpi4b"

DEPENDS += "trusted-firmware-a"

do_compile:prepend() {
	export BL31="${RECIPE_SYSROOT}/firmware/bl31.elf"
	ls -l ${BL31}
	export TEE="${RECIPE_SYSROOT}/lib/firmware/tee.elf"
	ls -l ${TEE}
}

do_deploy:append() {
	mkdir -p ${DEPLOYDIR}
	cp ${B}/rockpi4b_defconfig/idbloader.img  ${DEPLOYDIR}/idbloader.img
	cp ${B}/rockpi4b_defconfig/u-boot.itb ${DEPLOYDIR}/u-boot.itb
}

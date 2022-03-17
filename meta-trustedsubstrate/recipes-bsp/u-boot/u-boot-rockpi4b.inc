# Generate Rockchip style loader binaries
inherit deploy

SRCREV = "006fddde01da7e8b3c7cad4a35f3245edc894ab4"

SRC_URI:append = " file://rockpi4b_defconfig"
SRC_URI:append = " file://0004-phy-rockchip-inno-usb2-fix-hang-when-multiple-controllers-exit.patch"
SRC_URI:append = " file://0001-rk3399-rock-pi-4b-u-boot-add-optee-node.patch"
SRC_URI:append = " file://0002-rk3399-rock-pi-4b-u-boot-add-ftpm-dt-node.patch"

COMPATIBLE_MACHINE = "rockpi4b"

DEPENDS += "trusted-firmware-a"

PARALLEL_MAKE = ""

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

ATF_DEPENDS = " trusted-firmware-a:do_deploy"
do_compile[depends] .= "${ATF_DEPENDS}"

inherit deploy
NO_DTB_UBOOT="u-boot-nodtb.bin"

COMPATIBLE_MACHINE = "stm32mp157c-dk2"
SRC_URI:append = " file://stm32mp157c_dk2_trusted_defconfig"

do_deploy:append() {
	mkdir -p ${DEPLOYDIR}
	cp ${B}/stm32mp157c_dk2_trusted_defconfig/arch/arm/dts/stm32mp157c-dk2.dtb  ${DEPLOYDIR}/
	cp ${B}/stm32mp157c_dk2_trusted_defconfig/${NO_DTB_UBOOT}  ${DEPLOYDIR}/
}

inherit deploy

do_deploy:append() {
	mkdir -p ${DEPLOYDIR}
	cp ${B}/stm32mp157c_dk2_trusted_defconfig/arch/arm/dts/stm32mp157c-dk2.dtb  ${DEPLOYDIR}/
}

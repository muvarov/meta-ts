FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://ubootefi.var"

SRC_URI:append:synquacer = " file://0001-synquacer-add-fTPM-support.patch"
SRC_URI:append:synquacer = " file://0002-Revert-configs-synquacer-Make-U-Boot-binary-position.patch"
SRC_URI:append:synquacer = " file://0003-configs-synquacer-Fix-dfu_alt_info-to-use-nor1.patch"
SRC_URI:append:synquacer = " file://synquacer_developerbox_defconfig"

SRC_URI:append:stm32mp157c-dk2 = " file://stm32mp157c_dk2_trusted_defconfig"
COMPATIBLE_MACHINE:stm32mp157c-dk2 = "stm32mp157c-dk2"

SRC_URI:append:rockpi4b = " file://rockpi4b_defconfig"
COMPATIBLE_MACHINE:rockpi4b = "rockpi4b"

do_configure:prepend() {
	cp -r ${WORKDIR}/*_defconfig ${S}/configs/ || true
	cp ${WORKDIR}/ubootefi.var ${S}/
}


MACHINE_TFA_REQUIRE ?= ""

MACHINE_TFA_REQUIRE:ledge-rockpi4b = "u-boot-ledge_rockpi4b.inc"
 
require ${MACHINE_TFA_REQUIRE}



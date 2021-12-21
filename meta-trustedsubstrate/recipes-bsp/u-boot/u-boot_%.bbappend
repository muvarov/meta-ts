FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://ubootefi.var"

SRC_URI:append:stm32mp157c-dk2 = " file://stm32mp157c_dk2_trusted_defconfig"
COMPATIBLE_MACHINE:stm32mp157c-dk2 = "stm32mp157c-dk2"

SRC_URI:append:qemuarm64-secureboot = " file://qemu_arm64_defconfig"

do_configure:prepend() {
	cp -r ${WORKDIR}/*_defconfig ${S}/configs/ || true
	cp ${WORKDIR}/ubootefi.var ${S}/
}


MACHINE_UBOOT_REQUIRE ?= ""

MACHINE_UBOOT_REQUIRE:rockpi4b = "u-boot-rockpi4b.inc"
MACHINE_UBOOT_REQUIRE:rpi4 = "u-boot-rpi4.inc"
MACHINE_UBOOT_REQUIRE:synquacer = "u-boot-synquacer.inc"

require ${MACHINE_UBOOT_REQUIRE}

require u-boot-certs.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append:stm32mp157c-dk2 = " file://stm32mp157c_dk2_trusted_defconfig"
SRC_URI:append:stm32mp157c-ev1 = " file://stm32mp157c_ev1_trusted_defconfig"
COMPATIBLE_MACHINE:stm32mp157c-dk2 = "stm32mp157c-dk2"
COMPATIBLE_MACHINE:stm32mp157c-ev1 = "stm32mp157c-ev1"

SRC_URI:append:qemuarm64-secureboot = " file://qemu_arm64_defconfig"

do_configure:prepend() {
	cp -r ${WORKDIR}/*_defconfig ${S}/configs/ || true
}

MACHINE_UBOOT_REQUIRE ?= ""

MACHINE_UBOOT_REQUIRE:rockpi4b = "u-boot-rockpi4b.inc"
MACHINE_UBOOT_REQUIRE:rpi4 = "u-boot-rpi4.inc"
MACHINE_UBOOT_REQUIRE:synquacer = "u-boot-synquacer.inc"
MACHINE_UBOOT_REQUIRE:qemuarm64-secureboot = "u-boot-qemuarm64-secureboot.inc"
MACHINE_UBOOT_REQUIRE:stm32mp157c-dk2 = "u-boot-stm32mp157c-dk2.inc"
MACHINE_UBOOT_REQUIRE:stm32mp157c-ev1 = "u-boot-stm32mp157c-ev1.inc"

require ${MACHINE_UBOOT_REQUIRE}

require u-boot-certs.inc

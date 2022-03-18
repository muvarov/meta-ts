FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

# Always increment PR on u-boot config change or patches
PR="r1.ledge"

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
MACHINE_UBOOT_REQUIRE:zynqmp-starter = "u-boot-zynqmp-starter.inc"

require ${MACHINE_UBOOT_REQUIRE}

require u-boot-certs.inc

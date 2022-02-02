# ST STM32MP157 machines specific TFA support

COMPATIBLE_MACHINE = "stm32mp157c-ev1"

SRC_URI = "git://git.trustedfirmware.org/TF-A/trusted-firmware-a.git;protocol=https;name=tfa;branch=master"

# TF-A master branch with all Corstone1000 patches merged
SRCREV_tfa = "e537bcdedb16907ecab911e851c1dc4f35411b49"
PV .= "+git${SRCREV_tfa}"

LIC_FILES_CHKSUM="file://docs/license.rst;md5=b2c740efedc159745b9b31f88ff03dde"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/stm32mp1:"

SRC_URI:append = " file://0001-fix-stm32mp1-fix-dtc-version-check.patch"

TFA_DEBUG = "0"
TFA_UBOOT = "0"
TFA_MBEDTLS = "0"
TFA_BUILD_TARGET = "all fip"
TFA_INSTALL_TARGET = ""

TFA_TARGET_PLATFORM = "stm32mp1"
TFA_DEVICETREE = "stm32mp157c-ev1.dtb"

# Enabling Secure-EL1 Payload Dispatcher (SPD)
# TFA_SPD = "opteed"
# TFA_SPMD_SPM_AT_SEL2 = "0"

# BL2 loads BL32 (optee). So, optee needs to be built first:
DEPENDS += " optee-os u-boot"
DEPENDS += " dtc-native"

inherit deploy
# https://wiki.st.com/stm32mpu/wiki/How_to_configure_TF-A_FIP

EXTRA_OEMAKE:append = " \
                        ARCH=aarch32 ARM_ARCH_MAJOR=7 \
                        PLAT=${TFA_TARGET_PLATFORM} \
                        DTB_FILE_NAME=${TFA_DEVICETREE} \
                        AARCH32_SP=optee STM32MP_SDMMC=1 STM32MP_EMMC=1 \
                        BL33=${DEPLOY_DIR_IMAGE}/u-boot-nodtb.bin \
                        BL33_CFG=${DEPLOY_DIR_IMAGE}/stm32mp157c-ev1.dtb \
                        BL32=${RECIPE_SYSROOT}/lib/firmware/tee-header_v2.bin \
                        BL32_EXTRA1=${RECIPE_SYSROOT}/lib/firmware/tee-pager_v2.bin \
                        BL32_EXTRA2=${RECIPE_SYSROOT}/lib/firmware/tee-pageable_v2.bin \
                        LOG_LEVEL=1 \
			"

do_install:append() {
	mkdir -p ${D}/firmware
	cp ${B}/stm32mp1/release/tf-a-stm32mp157c-ev1.stm32 ${D}/firmware
	cp ${B}/stm32mp1/release/fip.bin ${D}/firmware/
}

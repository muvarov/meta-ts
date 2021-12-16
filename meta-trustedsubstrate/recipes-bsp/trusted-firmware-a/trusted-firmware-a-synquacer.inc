# Socionext Synquacer 64-bit machines specific TFA support

COMPATIBLE_MACHINE = "synquacer"

SRC_URI = "git://git.trustedfirmware.org/TF-A/trusted-firmware-a.git;protocol=https;name=tfa;branch=master"

# TF-A master branch with all Corstone1000 patches merged
SRCREV_tfa = "c158878249f1bd930906ebd744b90d3f2a8265f1"
PV .= "+git${SRCREV_tfa}"

LIC_FILES_CHKSUM="file://docs/license.rst;md5=713afe122abbe07f067f939ca3c480c5 file://mbedtls/LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/synquacer:"

SRC_URI:append = " \
		  file://0001-fiptool-Accept-fixed-offset-for-image.patch \
		  file://0002-fix-plat-synquacer-update-scmi-power-domain-off-hand.patch \
		  file://dummy.bin \
		 "

TFA_DEBUG = "1"
TFA_UBOOT = "1"
TFA_MBEDTLS = "1"
TFA_BUILD_TARGET = "all fip"
TFA_INSTALL_TARGET = "bl31 fip.bin"

TFA_TARGET_PLATFORM = "synquacer"

# Enabling Secure-EL1 Payload Dispatcher (SPD)
TFA_SPD = "opteed"
# Cortex-A35 supports Armv8.0-A (no S-EL2 execution state).
# So, the SPD SPMC component should run at the S-EL1 execution state
TFA_SPMD_SPM_AT_SEL2 = "0"

# BL2 loads BL32 (optee). So, optee needs to be built first:
DEPENDS += " optee-os virtual/bootloader scp-firmware"

EXTRA_OEMAKE:append = ' PRELOADED_BL33_BASE=0x08200000 SQ_USE_SCMI_DRIVER=1' 

EXTRA_OEMAKE:append = " \
                        ARCH=aarch64 \
                        TARGET_PLATFORM=${TFA_TARGET_PLATFORM} \
                        TRUSTED_BOARD_BOOT=1 \
                        ARM_ROTPK_LOCATION=devel_rsa  \
                        BL32=${RECIPE_SYSROOT}/lib/firmware/tee-pager_v2.bin \
                        LOG_LEVEL=50 \
			"
do_deploy:append() {
    echo "deploy synquacer"
    cd ${DEPLOYDIR}
    echo ${STAGING_DIR_TARGET}
    ${S}/tools/fiptool/fiptool create --tb-fw ${D}/firmware/bl31.bin \
        --soc-fw ${WORKDIR}/dummy.bin --scp-fw ${WORKDIR}/dummy.bin \
        --tos-fw ${STAGING_DIR_TARGET}/lib/firmware/tee-pager_v2.bin@380000 \
        fip_all_arm_tf_optee.bin
    cd -
}

TFA_FWUPD_BIN = "${DEPLOYDIR}/fip_all_arm_tf_optee.bin"
require trusted-firmware-a_fwupd.inc

addtask deploy before do_build after do_compile

FILES:${PN} = "/boot /firmware"

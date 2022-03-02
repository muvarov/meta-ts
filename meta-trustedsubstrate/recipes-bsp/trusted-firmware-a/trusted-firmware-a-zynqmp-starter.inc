# Xilinx kv260 open AI 

COMPATIBLE_MACHINE = "zynqmp-starter"

#SRC_URI = "git://git.trustedfirmware.org/TF-A/trusted-firmware-a.git;protocol=https;name=tfa;branch=master"
SRC_URI = "git://github.com/Xilinx/arm-trusted-firmware.git;protocol=https;name=tfa;branch=master"
SRCREV_tfa = "cd4a0270e27ef11edc7b6c4e266a2b9acb316b0e"
LIC_FILES_CHKSUM="file://docs/license.rst;md5=b2c740efedc159745b9b31f88ff03dde"
PV .= "+git${SRCREV_tfa}"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/zynqmp-starter:"
SRC_URI:append = " file://0001-feat-plat-xilinx-versal-Get-version-for-ATF-related-.patch"  
SRC_URI:append = " file://0002-feat-plat-xilinx-zynqmp-fix-feature-check-version-is.patch"

#TFA_DEBUG = "1"
TFA_UBOOT = "0"
#TFA_MBEDTLS = "1"
TFA_BUILD_TARGET = "all"
TFA_INSTALL_TARGET = "bl31"

TFA_TARGET_PLATFORM = "zynqmp"

# Enabling Secure-EL1 Payload Dispatcher (SPD)
# TFA_SPD = "opteed"

EXTRA_OEMAKE:append = " DEBUG=0 ZYNQMP_CONSOLE=cadence1 RESET_TO_BL31=1 PLAT=zynqmp \
						bl31 ZYNQMP_ATF_MEM_BASE=0xfffea000 ZYNQMP_ATF_MEM_SIZE=0x16000"

do_deploy:append() {
    echo "deploy zynqmp-starter bl31"
    cp ${D}/firmware/bl31.bin ${DEPLOYDIR}
}

addtask deploy before do_build after do_compile

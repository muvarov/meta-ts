# Xilinx kv260 open AI 

COMPATIBLE_MACHINE = "zynqmp-starter"

SRC_URI = "git://git.trustedfirmware.org/TF-A/trusted-firmware-a.git;protocol=https;name=tfa;branch=master"
SRCREV_tfa = "fee7b2d3b4dc4fcf225c5191a7aad8427489ef64"
LIC_FILES_CHKSUM="file://docs/license.rst;md5=b2c740efedc159745b9b31f88ff03dde"
PV .= "+git${SRCREV_tfa}"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/zynqmp-starter:"

TFA_DEBUG = "0"
TFA_UBOOT = "0"
#TFA_MBEDTLS = "1"
TFA_BUILD_TARGET = "all"
TFA_INSTALL_TARGET = "bl31"

TFA_TARGET_PLATFORM = "zynqmp"

# Enabling Secure-EL1 Payload Dispatcher (SPD)
# TFA_SPD = "opteed"

EXTRA_OEMAKE:append = " DEBUG=0 ZYNQMP_CONSOLE=cadence1 RESET_TO_BL31=1 PLAT=zynqmp \
						bl31 ZYNQMP_ATF_MEM_BASE=0xFFFE9000 ZYNQMP_ATF_MEM_SIZE=0x17000"

do_deploy:append() {
    echo "deploy zynqmp-starter bl31"
    cp ${D}/firmware/bl31.bin ${DEPLOYDIR}
}

addtask deploy before do_build after do_compile

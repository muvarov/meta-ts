SRC_URI = "git://git.trustedfirmware.org/OP-TEE/optee_os.git;protocol=https;branch=master"
SRCREV = "d21befa5e53eae9db469eba1685f5aa5c6f92c2f"

PV .= "+git${SRCREV}"

DEPENDS += "python3-pycryptodomex-native"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/optee-os/lede-rockpi4b:"

COMPATIBLE_MACHINE = "ledge-rockpi4b"

OPTEEMACHINE = "rockchip"
OPTEEOUTPUTMACHINE = "rockchip"
EXTRA_OEMAKE += " PLATFORM_FLAVOR=rk3399 ARCH=arm"

# Enable optee memory layout and boot logs
EXTRA_OEMAKE += " CFG_TEE_CORE_LOG_LEVEL=4"

# default disable latency benchmarks (over all OP-TEE layers)
EXTRA_OEMAKE +=  " CFG_TEE_BENCHMARK=n"

EXTRA_OEMAKE += " CFG_ARM64_core=y"
EXTRA_OEMAKE += " CFG_RPMB_FS=y"
EXTRA_OEMAKE += " CFG_RPMB_WRITE_KEY=1"
EXTRA_OEMAKE += " CFG_CORE_HEAP_SIZE=524288"

EXTRA_OEMAKE += " HOST_PREFIX=${HOST_PREFIX}"
EXTRA_OEMAKE += " CROSS_COMPILE64=${HOST_PREFIX}"

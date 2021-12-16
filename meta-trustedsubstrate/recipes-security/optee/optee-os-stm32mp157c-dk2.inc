SRC_URI = "git://git.trustedfirmware.org/OP-TEE/optee_os.git;protocol=https;branch=master"
SRCREV = "d21befa5e53eae9db469eba1685f5aa5c6f92c2f"
PV .= "+git${SRCREV}"

DEPENDS += "python3-pycryptodomex-native"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/optee-os/stm32mp157c-dk2:"

COMPATIBLE_MACHINE = "stm32mp157c-dk2"

OPTEEMACHINE = "stm32mp1"
OPTEEOUTPUTMACHINE = "stm32mp1"

# Enable optee memory layout and boot logs
EXTRA_OEMAKE += " CFG_TEE_CORE_LOG_LEVEL=4"

# default disable latency benchmarks (over all OP-TEE layers)
EXTRA_OEMAKE += " CFG_TEE_BENCHMARK=n"

EXTRA_OEMAKE:remove = "CFG_ARM64_core=y"
EXTRA_OEMAKE:remove = "ta-targets=ta_arm64"
EXTRA_OEMAKE:append = " CFG_ARM32_core=y ta-targets=ta_arm32 "

EXTRA_OEMAKE:append = " CFG_EMBED_DTB_SOURCE_FILE=stm32mp157c-dk2.dts "

EXTRA_OEMAKE += " HOST_PREFIX=${HOST_PREFIX}"
EXTRA_OEMAKE += " CROSS_COMPILE=${HOST_PREFIX}"

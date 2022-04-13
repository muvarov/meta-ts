DEPENDS += "python3-pycryptodomex-native"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/optee-os/stm32mp157c-dk2:"

COMPATIBLE_MACHINE = "stm32mp157c-dk2"

OPTEEMACHINE = "stm32mp1"
OPTEEOUTPUTMACHINE = "stm32mp1"

# Enable optee memory layout and boot logs
EXTRA_OEMAKE += " CFG_TEE_CORE_LOG_LEVEL=1"

# default disable latency benchmarks (over all OP-TEE layers)
EXTRA_OEMAKE += " CFG_TEE_BENCHMARK=n"

EXTRA_OEMAKE:remove = "CFG_ARM64_core=y"
EXTRA_OEMAKE:remove = "ta-targets=ta_arm64"
# inherited from our main .bbappend
EXTRA_OEMAKE:remove = "CFG_CORE_HEAP_SIZE=131072 "
EXTRA_OEMAKE:append = " CFG_ARM32_core=y ta-targets=ta_arm32 "

EXTRA_OEMAKE:append = " CFG_EMBED_DTB_SOURCE_FILE=stm32mp157c-dk2.dts "

EXTRA_OEMAKE += " HOST_PREFIX=${HOST_PREFIX}"
EXTRA_OEMAKE += " CROSS_COMPILE=${HOST_PREFIX}"

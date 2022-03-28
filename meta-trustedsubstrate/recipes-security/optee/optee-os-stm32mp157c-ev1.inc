DEPENDS += "python3-pycryptodomex-native edk2-firmware"

FILESEXTRAPATHS:prepend := "${THISDIR}/files/optee-os/stm32mp157c-dk2:"

COMPATIBLE_MACHINE = "stm32mp157c-ev1"

OPTEEMACHINE = "stm32mp1"
OPTEEOUTPUTMACHINE = "stm32mp1"

# Enable optee memory layout and boot logs
EXTRA_OEMAKE += " CFG_TEE_CORE_LOG_LEVEL=1"

# default disable latency benchmarks (over all OP-TEE layers)
EXTRA_OEMAKE += " CFG_TEE_BENCHMARK=n"

EXTRA_OEMAKE:remove = "CFG_ARM64_core=y"
EXTRA_OEMAKE:remove = "ta-targets=ta_arm64"
EXTRA_OEMAKE:append = " CFG_ARM32_core=y ta-targets=ta_arm32 "

EXTRA_OEMAKE:append = " CFG_EMBED_DTB_SOURCE_FILE=stm32mp157c-ev1.dts "

EXTRA_OEMAKE += " HOST_PREFIX=${HOST_PREFIX}"
EXTRA_OEMAKE += " CROSS_COMPILE=${HOST_PREFIX}"

# Include StandAloneMM
EXTRA_OEMAKE += ' CFG_RPMB_FS=y CFG_RPMB_FS_DEV_ID=1 CFG_RPMB_WRITE_KEY=y'
EXTRA_OEMAKE += ' CFG_CORE_HEAP_SIZE=65536 CFG_CORE_DYN_SHM=y CFG_RPMB_TESTKEY=y'
EXTRA_OEMAKE += ' CFG_REE_FS=n CFG_SCTLR_ALIGNMENT_CHECK=n'
EXTRA_OEMAKE += " CFG_STMM_PATH=${DEPLOY_DIR_IMAGE}/uefi.bin "

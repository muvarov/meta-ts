# Include machine specific configurations for UEFI EDK2

MACHINE_EDK2_REQUIRE ?= ""

MACHINE_EDK2_REQUIRE:synquacer = "stmm.inc"
MACHINE_EDK2_REQUIRE:stm32mp157c-ev1 = "stmm.inc"
MACHINE_EDK2_REQUIRE:rockpi4b = "stmm.inc"

# meta-arm doesn't export that for armv7
export GCC5_ARM_PREFIX = "${TARGET_PREFIX}"

require ${MACHINE_EDK2_REQUIRE}

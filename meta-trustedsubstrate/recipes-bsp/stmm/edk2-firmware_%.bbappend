# Include machine specific configurations for UEFI EDK2

MACHINE_EDK2_REQUIRE ?= ""

MACHINE_EDK2_REQUIRE:synquacer = "stmm.inc"

require ${MACHINE_EDK2_REQUIRE}


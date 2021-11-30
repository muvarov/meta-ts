# Machine specific configurations

MACHINE_OPTEE_OS_REQUIRE ?= ""
MACHINE_OPTEE_OS_REQUIRE:ledge-synquacer = "optee-os_synquacer.inc"

require ${MACHINE_OPTEE_OS_REQUIRE}

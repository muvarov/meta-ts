# Machine specific configurations

MACHINE_OPTEE_OS_REQUIRE ?= ""
MACHINE_OPTEE_OS_REQUIRE:ledge-synquacer = "optee-os_synquacer.inc"
MACHINE_OPTEE_OS_REQUIRE:ledge-stm32mp157c-dk2 = "optee-os_ledge-stm32mp157c-dk2.inc"

require ${MACHINE_OPTEE_OS_REQUIRE}

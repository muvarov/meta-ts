# Machine specific configurations

MACHINE_OPTEE_OS_REQUIRE ?= ""
MACHINE_OPTEE_OS_REQUIRE:synquacer = "optee-os_synquacer.inc"
MACHINE_OPTEE_OS_REQUIRE:stm32mp157c-dk2 = "optee-os-stm32mp157c-dk2.inc"
MACHINE_OPTEE_OS_REQUIRE:rockpi4b = "optee-os-rockpi4b.inc"

require ${MACHINE_OPTEE_OS_REQUIRE}

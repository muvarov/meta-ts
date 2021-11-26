# Machine specific configurations

MACHINE_OPTEE_CLIENT_REQUIRE ?= ""
MACHINE_OPTEE_CLIENT_REQUIRE:ledge-synquacer = "optee-client-synquacer.inc"

require ${MACHINE_OPTEE_CLIENT_REQUIRE}

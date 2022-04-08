# Machine specific configurations

MACHINE_OPTEE_TEST_REQUIRE ?= ""
MACHINE_OPTEE_TEST_REQUIRE:synquacer = "optee-test-synquacer.inc"

require ${MACHINE_OPTEE_TEST_REQUIRE}

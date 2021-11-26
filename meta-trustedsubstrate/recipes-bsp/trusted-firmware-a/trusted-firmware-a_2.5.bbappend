# Machine specific TFAs

MACHINE_TFA_REQUIRE ?= ""

MACHINE_TFA_REQUIRE:ledge-synquacer = "trusted-firmware-a-ledge_synquacer.inc"

require ${MACHINE_TFA_REQUIRE}

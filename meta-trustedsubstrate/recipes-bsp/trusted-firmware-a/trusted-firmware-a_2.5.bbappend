# Machine specific TFAs

MACHINE_TFA_REQUIRE ?= ""

MACHINE_TFA_REQUIRE:ledge-synquacer = "trusted-firmware-a-ledge_synquacer.inc"
MACHINE_TFA_REQUIRE:ledge-stm32mp157c-dk2 = "trusted-firmware-a-ledge_stm32mp157c-dk2.inc"
MACHINE_TFA_REQUIRE:ledge-rockpi4b = "trusted-firmware-a-ledge_rockpi4b.inc"
 
require ${MACHINE_TFA_REQUIRE}

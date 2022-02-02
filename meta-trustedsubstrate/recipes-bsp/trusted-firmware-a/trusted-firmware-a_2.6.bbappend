# Machine specific TFAs

MACHINE_TFA_REQUIRE ?= ""

MACHINE_TFA_REQUIRE:synquacer = "trusted-firmware-a-synquacer.inc"
MACHINE_TFA_REQUIRE:stm32mp157c-dk2 = "trusted-firmware-a-stm32mp157c-dk2.inc"
MACHINE_TFA_REQUIRE:stm32mp157c-ev1 = "trusted-firmware-a-stm32mp157c-ev1.inc"
MACHINE_TFA_REQUIRE:rockpi4b = "trusted-firmware-a-rockpi4b.inc"
 
require ${MACHINE_TFA_REQUIRE}

# Machine specific configurations

DEPENDS:append = " dtc-native"

MACHINE_OPTEE_OS_REQUIRE ?= ""
MACHINE_OPTEE_OS_REQUIRE:synquacer = "optee-os_synquacer.inc"
MACHINE_OPTEE_OS_REQUIRE:stm32mp157c-dk2 = "optee-os-stm32mp157c-dk2.inc"
MACHINE_OPTEE_OS_REQUIRE:stm32mp157c-ev1 = "optee-os-stm32mp157c-ev1.inc"
MACHINE_OPTEE_OS_REQUIRE:rockpi4b = "optee-os-rockpi4b.inc"

require ${MACHINE_OPTEE_OS_REQUIRE}

# Add PKCS11 as early TA
DEPENDS += " python3-cryptography-native "
EXTRA_OEMAKE:append = " CFG_IN_TREE_EARLY_TAS=pkcs11/fd02c9da-306c-48c7-a49c-bbd827ae86ee "

# Generate Rockchip style loader binaries

SRC_URI:append:rpi4 = " file://rpi4_defconfig"
COMPATIBLE_MACHINE:rpi4 = "rpi4"

SRCREV="c03942ddc9e88d86d919504299905e4e8b0003cd"
DEPENDS += "rpi4-firmware"

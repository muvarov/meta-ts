# Generate Rockchip style loader binaries

SRC_URI:append:rpi4 = " file://rpi4_defconfig"
COMPATIBLE_MACHINE:rpi4 = "rpi4"

DEPENDS += "rpi4-firmware"

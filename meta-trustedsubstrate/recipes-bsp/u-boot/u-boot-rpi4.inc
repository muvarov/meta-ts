# Generate Rockchip style loader binaries

SRC_URI:append:rpi4 = " file://rpi4_defconfig"
COMPATIBLE_MACHINE:rpi4 = "rpi4"

# v2022.01
SRCREV="d637294e264adfeb29f390dfc393106fd4d41b17"
DEPENDS += "rpi4-firmware"

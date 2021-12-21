FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"
FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}/synquacer:"

SRC_URI:append = " file://0001-synquacer-add-fTPM-support.patch"
SRC_URI:append = " file://0002-Revert-configs-synquacer-Make-U-Boot-binary-position.patch"
SRC_URI:append = " file://0003-configs-synquacer-Fix-dfu_alt_info-to-use-nor1.patch"
SRC_URI:append = " file://synquacer_developerbox_defconfig"

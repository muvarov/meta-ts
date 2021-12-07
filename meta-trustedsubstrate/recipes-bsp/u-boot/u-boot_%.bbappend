FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://ubootefi.var"

SRC_URI:append:ledge-synquacer = " file://0001-synquacer-add-fTPM-support.patch"
SRC_URI:append:ledge-synquacer = " file://0002-Revert-configs-synquacer-Make-U-Boot-binary-position.patch"
SRC_URI:append:ledge-synquacer = " file://0003-configs-synquacer-Fix-dfu_alt_info-to-use-nor1.patch"
SRC_URI:append:ledge-synquacer = " file://synquacer_developerbox_defconfig"

SRC_URI:append:ledge-stm32mp157c-dk2 = " file://ledge_stm32mp157c_dk2_trusted_defconfig"
COMPATIBLE_MACHINE:ledge-stm32mp157c-dk2 = "ledge-stm32mp157c-dk2"

do_configure:prepend() {
	cp -r ${WORKDIR}/*_defconfig ${S}/configs/
	cp ${WORKDIR}/ubootefi.var ${S}/
}


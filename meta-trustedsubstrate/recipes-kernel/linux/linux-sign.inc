DEPENDS:append = " e2fsprogs-native  efitools-native  coreutils-native "

FILESEXTRAPATHS:prepend := "${THISDIR}/files/:"
SRC_URI:append = " file://uefi-certificates/db.key"
SRC_URI:append = " file://uefi-certificates/db.crt"

inherit kernel siteinfo

do_compile:append() {
	KERNEL_IMAGE=`find ${B} -name ${KERNEL_IMAGETYPE} -print -quit`

	${STAGING_BINDIR_NATIVE}/sbsign --key ${WORKDIR}/uefi-certificates/db.key --cert ${WORKDIR}/uefi-certificates/db.crt ${KERNEL_IMAGE} --output  ${KERNEL_IMAGETYPE}.signed
	cp ${KERNEL_IMAGETYPE}.signed ${KERNEL_IMAGE}
}

do_deploy:append() {
	KERNEL_IMAGE="${D}/boot/${img}"

	install -m 0644 ${KERNEL_IMAGETYPE}.signed ${DEPLOYDIR}/
}

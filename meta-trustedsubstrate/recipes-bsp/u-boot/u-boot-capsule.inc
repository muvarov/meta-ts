FILESEXTRAPATHS:prepend := "${THISDIR}/u-boot/capsule:"

SRC_URI += " \
	file://0001-tools-mkeficapsule-output-messages-to-stderr-instead.patch \
	file://0002-tools-mkeficapsule-rework-the-code-a-little-bit.patch \
	file://0003-tools-build-mkeficapsule-with-tools-only_defconfig.patch \
	file://0004-tools-mkeficapsule-add-firmware-image-signing.patch \
	file://0005-tools-mkeficapsule-add-man-page.patch \
	file://0006-doc-update-UEFI-document-for-usage-of-mkeficapsule.patch \
	file://0007-test-py-efi_capsule-add-image-authentication-test.patch \
	file://0008-tools-mkeficapsule-allow-for-specifying-GUID-explici.patch \
	file://0009-test-py-efi_capsule-align-with-the-syntax-change-of-.patch \
	file://0010-test-py-efi_capsule-add-a-test-for-guid-option.patch \
	file://0011-test-py-efi_capsule-check-the-results-in-case-of-CAP.patch \
"

SRC_URI:append = " file://uefi-certificates/db.key"
SRC_URI:append = " file://uefi-certificates/db.crt"

do_compile:append() {
	${B}/tools/mkeficapsule --raw  --index 0 --instance 0 \
		--private-key ${WORKDIR}/uefi-certificates/db.key --certificate ${WORKDIR}/uefi-certificates/db.crt \
		--monotonic-count 1 u-boot.bin u-boot.cap
}

do_deploy:append() {
	mkdir -p ${DEPLOYDIR}
	cp ${B}/u-boot.cap ${DEPLOYDIR}/u-boot.cap
}

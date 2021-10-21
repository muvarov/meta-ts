FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# EDK2 variables files with defined initrd variable

SRC_URI += "\
	file://RELEASEAARCH64_QEMU_EFI.fd.gz \
	file://LEDGE_AARCH64_QEMU_VARS.fd.gz \
	file://RELEASEARM_QEMU_EFI.fd.gz \
	file://LEDGE_ARM_QEMU_VARS.fd.gz \
	file://LEDGE_RELEASEX64_OVMF.fd.gz \
	"

do_deploy_append() {
	mkdir -p ${D}/boot/EFI/BOOT
}

do_deploy_append_aarch64_qemuall() {
    install -m 0644 ${WORKDIR}/LEDGE_AARCH64_QEMU_VARS.fd ${DEPLOYDIR}/LEDGE_AARCH64_QEMU_VARS.bin
}

do_deploy_append_arm_qemuall() {
    install -m 0644 ${WORKDIR}/LEDGE_ARM_QEMU_VARS.fd ${DEPLOYDIR}/LEDGE_ARM_QEMU_VARS.bin
}

do_deploy_append_ledge-qemux86-64() {
    install -m 0644 ${WORKDIR}/LEDGE_RELEASEX64_OVMF.fd ${DEPLOYDIR}/firmware.uefi.edk2.bin
}

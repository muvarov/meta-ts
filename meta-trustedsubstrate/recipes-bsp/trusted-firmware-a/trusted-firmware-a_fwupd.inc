U_BOOT__FMR_RAW_GUID = "e2bb9c06-70e9-4b14-97a3-5a7913176e3f"

TFA_FUPD_GUID ?= "${U_BOOT__FMR_RAW_GUID}"

DEPENDS:append = " firmware-packager-native gcab-native"
do_deploy:append() {
	cd ${DEPLOYDIR}
	${STAGING_DIR_NATIVE}/${bindir}/firmware_packager/firmware_packager.py --firmware-name ${TFA_TARGET_PLATFORM} --release-version 1.0.1 \
	--bin ${TFA_FWUPD_BIN} \
	--out ${TFA_TARGET_PLATFORM}-firmware.cab --device-guid ${TFA_FUPD_GUID} \
	--developer-name LedgeBuild \
	--version-format 1.7 \
	--update-protocol org.uefi.capsule
}

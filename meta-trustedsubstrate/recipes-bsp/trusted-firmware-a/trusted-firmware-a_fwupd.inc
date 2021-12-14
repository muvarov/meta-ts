
DEPENDS:append = " firmware-packager-native gcab-native"
do_deploy:append() {
	cd ${DEPLOYDIR}
	${STAGING_DIR_NATIVE}/${bindir}/firmware_packager/firmware_packager.py --firmware-name ${TFA_TARGET_PLATFORM} --release-version 1.0.1 \
	--bin ${TFA_FWUPD_BIN} \
	--out ${TFA_TARGET_PLATFORM}-firmware.cab --device-guid 230c8b18-8d9b-53ec-838b-6cfc0383493a \
	--developer-name LedgeBuild \
	--version-format 1.7 \
	--update-protocol fwupd
}

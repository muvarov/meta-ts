DEPENDS += " python3-pyopenssl-native"

do_compile:prepend() {
	if [ -e "${UEFI_CERT_FILE}" ]; then
		mkdir -p uefi_certs
		tar xpvfz ${UEFI_CERT_FILE} -C uefi_certs

		${S}/tools/efivar.py set -i ${S}/ubootefi.var -n pk  -d uefi_certs/PK.esl  -t file
		${S}/tools/efivar.py set -i ${S}/ubootefi.var -n kek -d uefi_certs/KEK.esl -t file
		${S}/tools/efivar.py set -i ${S}/ubootefi.var -n db  -d uefi_certs/db.esl  -t file
		${S}/tools/efivar.py set -i ${S}/ubootefi.var -n dbx -d uefi_certs/dbx.esl -t file
		${S}/tools/efivar.py print -i ${S}/ubootefi.var
		rm -rf uefi_certs
	else
		touch ${S}/ubootefi.var
	fi
}

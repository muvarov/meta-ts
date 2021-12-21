DEPENDS += " python3-pyopenssl-native"

SRC_URI += "file://uefi-certificates/db.esl"
SRC_URI += "file://uefi-certificates/dbx.esl"
SRC_URI += "file://uefi-certificates/KEK.esl"
SRC_URI += "file://uefi-certificates/PK.esl"

SRC_URI += "file://uefi-certificates/ms.esl"

SRC_URI += "file://0001-efi_loader-Don-t-authenticate-certificates-with-CAs.patch"

do_compile:prepend() {
	${S}/tools/efivar.py set -i ubootefi.var -n pk  -d ${WORKDIR}/uefi-certificates/PK.esl  -t file
	${S}/tools/efivar.py set -i ubootefi.var -n kek -d ${WORKDIR}/uefi-certificates/KEK.esl -t file
	${S}/tools/efivar.py set -i ubootefi.var -n db  -d ${WORKDIR}/uefi-certificates/db.esl  -t file
	${S}/tools/efivar.py set -i ubootefi.var -n dbx -d ${WORKDIR}/uefi-certificates/dbx.esl -t file


	${S}/tools/efivar.py set -i ubootefi.var -n db  -d ${WORKDIR}/uefi-certificates/ms.esl  -t file

	${S}/tools/efivar.py print -i ubootefi.var
}

DEPENDS += " python3-pyopenssl-native"

SRC_URI += "file://uefi-certificates/db.esl"
SRC_URI += "file://uefi-certificates/dbx.esl"
SRC_URI += "file://uefi-certificates/KEK.esl"
SRC_URI += "file://uefi-certificates/PK.esl"

SRC_URI += "file://uefi-certificates/ms.esl"

do_compile:prepend() {
	${S}/tools/efivar.py set -i ${S}/ubootefi.var -n pk  -d ${WORKDIR}/uefi-certificates/PK.esl  -t file
	${S}/tools/efivar.py set -i ${S}/ubootefi.var -n kek -d ${WORKDIR}/uefi-certificates/KEK.esl -t file

	cat  ${WORKDIR}/uefi-certificates/db.esl ${WORKDIR}/uefi-certificates/ms.esl > db.esl
	${S}/tools/efivar.py set -i ${S}/ubootefi.var -n db  -d db.esl  -t file

	${S}/tools/efivar.py set -i ${S}/ubootefi.var -n dbx -d ${WORKDIR}/uefi-certificates/dbx.esl -t file

	${S}/tools/efivar.py print -i ${S}/ubootefi.var
}

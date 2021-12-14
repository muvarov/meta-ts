#Use firmware_packager.py on host to create firmware update
inherit native

SUMMARY = "A simple daemon to allow session software to update firmware"
LICENSE = "LGPL-2.1+"
LIC_FILES_CHKSUM = "file://COPYING;md5=4fbd65380cdd255951079008b364516c"

SRC_URI = "https://github.com/fwupd/fwupd/releases/download/1.7.3/fwupd-1.7.3.tar.xz"
SRC_URI[sha256sum] = "109dacc16ed0db71eb08b852e96b070b8c2c53516a3071b9d0683acd8ecd42d9"

UPSTREAM_CHECK_URI = "https://github.com/fwupd/fwupd/releases"

S = "${WORKDIR}/fwupd-1.7.3"

BBCLASSEXTEND = "native nativesdk"

do_compile() {
	echo "nothing"
}

do_install() {
	mkdir -p ${D}/${bindir}/
	cp -a ${S}/contrib/firmware_packager  ${D}/${bindir}/
}

FILES_${PN} += "${bindir}/firmware_packager/firmware_packager.py"

SUMMARY = "Firmware binaries for RPi4"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://LICENCE.broadcom;md5=c403841ff2837657b2ed8e5bb474ac8d"

inherit deploy
DEPENDS += " dtc-native"

SRCREV="1.20210831"
SRC_URI = "https://github.com/raspberrypi/firmware/archive/refs/tags/${SRCREV}.tar.gz"
SRC_URI[sha256sum] = "47f879cd2b58cf556a9da95820af982d93929dfa4ff22488fc0bb271025c02ef"

SRC_URI:append = " file://config.txt"
SRC_URI:append = " file://tpm-soft-spi.dts"

S = "${WORKDIR}/firmware-${SRCREV}/boot"

FILES:${PN} = "firmware"
INSANE_SKIP:${PN} = "arch textrel already-stripped"
do_install() {
    install -d ${D}/firmware/overlays
    install -D "${S}/bcm2711-rpi-4-b.dtb" "${D}/firmware/"
    install -D ${S}/start4.elf ${D}/firmware/
    install -D ${S}/fixup4.dat ${D}/firmware/
    install -D ${WORKDIR}/config.txt ${D}/firmware/
    install -D ${S}/overlays/* ${D}/firmware/overlays
    dtc -O dtb -b 0 -@ ${WORKDIR}/tpm-soft-spi.dts -o ${D}/firmware/overlays/tpm-soft-spi.dtbo
}
# Only include RPi4b firmware and dtb
do_deploy() {
    # Copy the images to deploy directory
    cp -rf ${D}/firmware/* ${DEPLOYDIR}/
}
addtask deploy after do_install

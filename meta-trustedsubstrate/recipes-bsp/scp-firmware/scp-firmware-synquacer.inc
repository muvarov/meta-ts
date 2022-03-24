SRCREV  = "3a6c9511b121d04876ba745655dd190eae79aca4"

LIC_FILES_CHKSUM = "file://license.md;beginline=5;md5=9db9e3d2fb8d9300a6c3d15101b19731 \
                    file://contrib/cmsis/git/LICENSE.txt;md5=e3fc50a88d0a364313df4b21ef20c29e"

SCP_PLATFORM  = "synquacer"
FW_TARGETS = "scp"
SCP_LOG_LEVEL = "WARN"

COMPATIBLE_MACHINE:synquacer = "synquacer"

ROMRAMFW_FILE = "scp_romramfw_${SCP_BUILD_STR}.bin"

SRC_URI:remove = "file://0001-smt-Make-status-and-length-volatile-for-mod_smt_memo.patch"

do_deploy:append() {
    cd ${DEPLOYDIR}
    tr "\000" "\377" < /dev/zero | dd of=${ROMRAMFW_FILE} bs=1 count=196608
    dd if=scp_romfw.bin of=${ROMRAMFW_FILE} bs=1 conv=notrunc seek=0
    dd if=scp_ramfw.bin of=${ROMRAMFW_FILE} bs=1 seek=65536
}

PV = "2.9.0"

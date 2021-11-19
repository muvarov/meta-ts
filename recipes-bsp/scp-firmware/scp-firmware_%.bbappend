SRCREV  = "77ffab90a9f6071850475087cc5d40610c621126"

LIC_FILES_CHKSUM = "file://license.md;beginline=5;md5=9db9e3d2fb8d9300a6c3d15101b19731 \
                    file://contrib/cmsis/git/LICENSE.txt;md5=e3fc50a88d0a364313df4b21ef20c29e"

SCP_PLATFORM  = "synquacer"
FW_TARGETS = "scp"
SCP_LOG_LEVEL = "WARN"

COMPATIBLE_MACHINE_ledge-synquacer = "ledge-synquacer"

ROMRAMFW_FILE = "scp_romramfw_${SCP_BUILD_STR}.bin"

SRC_URI_remove = "file://0001-tools-gen_module_code-atomically-rewrite-the-generat.patch"

do_deploy_append_ledge-synquacer() {
    cd ${DEPLOYDIR}
    tr "\000" "\377" < /dev/zero | dd of=${ROMRAMFW_FILE} bs=1 count=196608
    dd if=scp_romfw.bin of=${ROMRAMFW_FILE} bs=1 conv=notrunc seek=0
    dd if=scp_ramfw.bin of=${ROMRAMFW_FILE} bs=1 seek=65536
}

PV = "2.9.0"


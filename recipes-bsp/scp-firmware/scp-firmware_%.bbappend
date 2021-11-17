#SRCREV    = "7a025658d8318e95dbab4259a8ff7834ae6d8061"
SCP_PLATFORM  = "synquacer"
FW_TARGETS = "scp"
SCP_LOG_LEVEL = "INFO"

COMPATIBLE_MACHINE_ledge-synquacer = "ledge-synquacer"

ROMRAMFW_FILE = "scp_romramfw_${SCP_BUILD_STR}.bin"

do_deploy_append_ledge-synquacer() {
    cd ${DEPLOYDIR}
    tr "\000" "\377" < /dev/zero | dd of=${ROMRAMFW_FILE} bs=1 count=196608
    dd if=scp_romfw.bin of=${ROMRAMFW_FILE} bs=1 conv=notrunc seek=0
    dd if=scp_ramfw.bin of=${ROMRAMFW_FILE} bs=1 seek=65536
}

PV = "2.6.0+git${SRCPV}"


# qemuarm64-secureboot  machines specific TFA support

COMPATIBLE_MACHINE = "qemuarm64-secureboot"

do_compile:append:qemuarm64-secureboot() {
    # Create a secure flash image for booting AArch64 Qemu. See:
    # https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git/tree/docs/plat/qemu.rst
    dd if=/dev/zero of=${BUILD_DIR}/flash.bin bs=1M count=64
    dd if=${BUILD_DIR}/bl1.bin of=${BUILD_DIR}/flash.bin bs=4096 conv=notrunc
    dd if=${BUILD_DIR}/fip.bin of=${BUILD_DIR}/flash.bin seek=64 bs=4096 conv=notrunc
}

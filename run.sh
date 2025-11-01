rm -rf build
make

# Boot Kernel in QEMU
echo "Ready."
qemu-system-i386 -kernel build/kernel.bin

make clean

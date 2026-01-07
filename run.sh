rm -rf build
make

# Boot Kernel in QEMU
echo -e "\e[32mReady.\e[0m"
qemu-system-i386 -kernel build/kernel.bin

make clean

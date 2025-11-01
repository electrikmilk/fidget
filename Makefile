all: build/boot.o build/kernel.o build/kernel.bin

build/boot.o:
	mkdir -p build
	nasm -f elf32 boot/boot.asm -o build/boot.o

build/kernel.o:
	cc -m32 -c kernel.c -o build/kernel.o -v

build/kernel.bin:
	ld -m elf_i386 -T boot/link.ld -o build/kernel.bin build/boot.o build/kernel.o

clean:
	rm build/boot.o build/kernel.o

all: build/kernel.bin

build/boot.o:
	mkdir -p build
	nasm -f elf32 boot/boot.asm -o build/boot.o

build/kernel.o: kernel.c
	cc -m32 -c kernel.c -o build/kernel.o

build/main.o: main.c
	cc -m32 -c main.c -o build/main.o

build/io.o: io.c
	cc -m32 -c io.c -o build/io.o

build/vga.o: vga.c
	cc -m32 -c vga.c -o build/vga.o

build/string.o: string.c
	cc -m32 -c string.c -o build/string.o

build/kernel.bin: build/boot.o build/kernel.o build/main.o build/io.o build/vga.o build/string.o
	ld -m elf_i386 -T boot/link.ld -o build/kernel.bin build/boot.o build/kernel.o build/main.o build/io.o build/vga.o build/string.o

clean:
	rm -rf build

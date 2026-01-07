//
// Created by brandon on 1/6/26.
//

#include "io.h"
#include "string.h"
#include "vga.h"

void line_feed() {
    col_idx = 0;
    if (line_idx >= VGA_HEIGHT) {
        line_idx = 0;
        clear_screen();
    }
    vga_buffer_pos = VGA_WIDTH * line_idx;
    ++line_idx;
}

void carriage_return() {
    --line_idx;
    col_idx = 0;
    vga_buffer_pos = VGA_WIDTH * line_idx;
}

int print(const char *str) {
    const unsigned short int str_len = strlen(str);
    for (unsigned short int i = 0; i < str_len; i++) {
        if (col_idx >= VGA_WIDTH) {
            ++line_idx;
            line_feed();
        }

        char print_character = str[i];

        switch(str[i]) {
        case '\n':
            line_feed();
            continue;
        case '\r':
            carriage_return();
            continue;
            // case '%':
            //     switch (str[i+1]) {
            //         case 'd':
            //             char* integer;
            //             itoa(, integer);
            //             break;
            //         case 's':
            //             printf(va_arg())
            //     }
            //     ++i;
            //     continue;
        }

        vga_buffer[vga_buffer_pos] = print_character;
        vga_buffer[vga_buffer_pos+1] = 0x0F;

        vga_buffer_pos += 2;
        ++col_idx;
    }

    return 1;
}

unsigned char inb(unsigned short port)
{
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void outb(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}
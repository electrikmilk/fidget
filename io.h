//
// Created by brandon on 1/2/24.
//

#ifndef FIDGET_IO_H
#define FIDGET_IO_H

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

// static inline void outb(int port, int val) {
//
// }

#endif //FIDGET_IO_H

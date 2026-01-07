#include "vga.h"

char* vga_buffer = (char*) VGA_ADDRESS; // VGA screen buffer

unsigned int vga_buffer_pos = 0;
unsigned int col_idx = 1;
unsigned int line_idx = 1;

unsigned short const vga_buffer_limit = (VGA_WIDTH * 2) * VGA_HEIGHT;

/* Fills the screen with white background and black text */
void clear_screen() {
    unsigned short limit = (VGA_WIDTH * 2) * VGA_HEIGHT;
    for (unsigned short i = 0; i < limit; ++i) {
        vga_buffer[i] = 0;
    }
    vga_buffer_pos = 0;
}

void fill_color(unsigned color) {
    for (unsigned short i = 0; i < vga_buffer_limit; ++i) {
        vga_buffer[i] = ' ';
        vga_buffer[i+1] = color;
        ++i;
    }
    vga_buffer_pos = 0;
}

void new_line() {
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
    const unsigned int str_len = strlen(str);
    for (unsigned short int i = 0; i < str_len; i++) {
        if (col_idx >= VGA_WIDTH) {
            ++line_idx;
            new_line();
        }

        char print_character = str[i];

        switch(str[i]) {
        case '\n':
            new_line();
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

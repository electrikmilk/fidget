//
// Created by brandon on 8/13/23.
//

#ifndef FIDGET_VGA_H
#define FIDGET_VGA_H

#define VGA_ADDRESS 0xb8000
#define VGA_HEIGHT 80
#define VGA_WIDTH 160

enum COLOR {
    BLACK = 0x0,
    BLUE = 0x1,
    GREEN = 0x2,
    CYAN = 0x3,
    RED = 0x4,
    MAGENTA = 0x5,
    BROWN = 0x6,
    LIGHT_GRAY = 0x7,
    DARK_GRAY = 0x8,
    LIGHT_BLUE = 0x9,
    LIGHT_GREEN = 0xA,
    LIGHT_CYAN = 0xB,
    LIGHT_RED = 0xC,
    PINK = 0xD,
    YELLOW = 0xE,
    WHITE = 0xF,
};

extern char* vga_buffer;
extern unsigned int vga_buffer_pos;
extern unsigned int col_idx;
extern unsigned int line_idx;

/* Fills the screen with white background and black text */
void clear_screen();

extern unsigned short const vga_buffer_limit;

void fill_color(unsigned color);

// void disable_cursor()
// {
//     outb(0x3D4, 0x0A);
//     outb(0x3D5, 0x20);
// }

#endif //FIDGET_VGA_H

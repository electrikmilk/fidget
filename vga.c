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
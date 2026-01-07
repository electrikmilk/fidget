//
// Created by brandon on 1/6/26.
//

#include "io.h"
#include "string.h"
#include "vga.h"



unsigned char inb(unsigned short port)
{
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void outb(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}
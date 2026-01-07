//
// Created by electrikmilk on 1/6/26.
//

// Input byte from port.
unsigned char inb(unsigned short port)
{
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

// Output byte data to port.
void outb(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}
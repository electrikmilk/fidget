//
// Created by brandon on 1/2/24.
//

#ifndef FIDGET_IO_H
#define FIDGET_IO_H

void line_feed();

void carriage_return();

int print(const char *str);

unsigned char inb(unsigned short port);

void outb(unsigned short port, unsigned char data);

#endif //FIDGET_IO_H

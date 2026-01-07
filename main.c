//
// Created by electrikmilk on 2/3/24.
//

//#include "kernel.h"
#include "vga.h"

int main() {
    clear_screen();
    print("Hello!\nWorld\n");
    print("Hello\rGoodbye\n\n");

    print_int(0);

    print("\n");

    return 0;
}

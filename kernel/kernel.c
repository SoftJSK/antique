#include "sysfunctions.h"
#include "keyboard.h"
#include "kernel.h"

unsigned short *terminal_buffer;
unsigned int vga_index;

void clearScreen() {
    int index = 0;
    // there are 25 lines each of 80 columns each element takes 2 bytes
    while (index < 80 * 25 * 2) {
        terminal_buffer[index] = ' ';
        index += 2;
    }
}

void print(char *str, unsigned char color) {
    int index = 0;
    while (str[index]) {
        terminal_buffer[vga_index] = (unsigned short)str[index]|(unsigned short)color << 8;
        index++;
        vga_index++;
    }
}

void newLine() {
    vga_index = 80;
}

int main() {
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    vga_index = 0;
    clear_screen();
    print("Antique", WHITE_COLOR);
    newLine();
    print("This is it for now", WHITE_COLOR);
    return 0;
}
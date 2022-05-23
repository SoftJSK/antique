#include "sysfunctions.h"
#include "keyboard.h"
#include "kernel.h"

static unsigned short *terminal_buffer;
static unsigned int vga_index;

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

void printChar(char str, unsigned char color) {
    int index = 0;
    terminal_buffer[vga_index] = str | (unsigned short)color << 8;
    index++;
    vga_index++;
    
}

void newLine() {
    vga_index = 80;
}

int main() {
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    vga_index = 0;
    clearScreen();
    while (1) {
        print("Antique: ", WHITE_COLOR);
        keyboardHandler();
        newLine();
    }
    return 0;
}
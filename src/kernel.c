#include "sysfunctions.h"
#include "keyboard.h"
#include "kernel.h"

static unsigned short *terminal_buffer;
static unsigned int vga_index;

void clearScreen() {
    int index = 0;
    // there are 25 lines each of 80 columns
    while (index < 160 * 50 * 4) {
        terminal_buffer[index] = ' ';
        index += 1;
    }
    vga_index = 0;
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
    vga_index = 80; // newline does not work currently
}

int main() {
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    vga_index = 0;
    clearScreen();
    while(1) {
        vga_index = 0;
        print("    -----------------------------", WHITE_COLOR);
        newLine();
        print("  /                               '\'", WHITE_COLOR);
        vga_index = 160;
        print("|                 |                 |", WHITE_COLOR);
        vga_index = 240;
        print("|                | |                |", WHITE_COLOR);
        vga_index = 320;
        print("|               |   |               |", WHITE_COLOR);
        vga_index = 400;
        print("|              |     |              |", WHITE_COLOR);
        vga_index = 480;
        print("|             |       |             |", WHITE_COLOR);
        vga_index = 560;
        print("|            |         |            |", WHITE_COLOR);
        vga_index = 640;
        print("|           |-----------|           |", WHITE_COLOR);
        vga_index = 720;
        print("|          |             |          |", WHITE_COLOR);
        vga_index = 800;
        print("|         |               |         |", WHITE_COLOR);
        vga_index = 880;
        print("|        |                 |        |", WHITE_COLOR);
        vga_index = 960;
        print("|       |                   |       |", WHITE_COLOR);
        vga_index = 1040;
        print("|      |                     |      |", WHITE_COLOR);
        vga_index = 1120;
        print("  '\'                               /", WHITE_COLOR);
        vga_index = 1200;
        print("    -----------------------------", WHITE_COLOR);
        vga_index = 1280;
        print("Welcome to Antique!", WHITE_COLOR);
        vga_index = 1360;
        print("By SoftJSK", WHITE_COLOR);
        vga_index = 1440;
        print("Keyboard test:", WHITE_COLOR);
        keyboardHandler();
        vga_index = 1520;
        print("Press TAB to erase text.", GREEN);
        vga_index = 1600;
    }
    return 0;
}
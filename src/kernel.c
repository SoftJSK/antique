#include "sysfunctions.h"
#include "keyboard.h"
#include "kernel.h"
#include "math.h"

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
    unsigned int calc_index = vga_index + 80;
    ifloor(calc_index);
    if ((calc_index % 80) == 0) {
        vga_index = calc_index;
    } else {
        while ((calc_index % 80) != 0) {
            calc_index--;
        }
        vga_index = calc_index;
    }

}

int main() {
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    vga_index = 0;
    clearScreen();
    print("    -----------------------------", WHITE_COLOR);
    newLine();
    print("  /                               '\'", WHITE_COLOR);
    newLine();
    print("|                 |                 |", WHITE_COLOR);
    newLine();
    print("|                | |                |", WHITE_COLOR);
    newLine();
    print("|               |   |               |", WHITE_COLOR);
    newLine();
    print("|              |     |              |", WHITE_COLOR);
    newLine();
    print("|             |       |             |", WHITE_COLOR);
    newLine();
    print("|            |         |            |", WHITE_COLOR);
    newLine();
    print("|           |-----------|           |", WHITE_COLOR);
    newLine();
    print("|          |             |          |", WHITE_COLOR);
    newLine();
    print("|         |               |         |", WHITE_COLOR);
    newLine();
    print("|        |                 |        |", WHITE_COLOR);
    newLine();
    print("|       |                   |       |", WHITE_COLOR);
    newLine();
    print("|      |                     |      |", WHITE_COLOR);
    newLine();
    print("  '\'                               /", WHITE_COLOR);
    newLine();
    print("    -----------------------------", WHITE_COLOR);
    newLine();
    print("Welcome to Antique!", WHITE_COLOR);
    newLine();
    print("By SoftJSK", WHITE_COLOR);
    newLine();
    print("Keyboard test:", WHITE_COLOR);
    keyboardHandler();
    newLine();
    print("Press TAB to erase text.", GREEN);
    newLine();

    return 0;
}
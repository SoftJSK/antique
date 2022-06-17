#ifndef KERNEL_H
#define KERNEL_H

#define VGA_ADDRESS 0xB8000
#define BLACK 0
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE_COLOR 15

void print(char* str, unsigned char color);
void printChar(char str, unsigned char color);
void clearScreen(void);
void newLine(void);

#endif
#include "keyboard.h"  
#include "kernel.h"

int clicked = 0;
int canSend = 0;

static unsigned short *terminal_buffer;
static unsigned int vga_index;

static __inline unsigned char
inb (unsigned short int __port)
{
  unsigned char _v;

  __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (__port));
  return _v;
}


unsigned char getScancode()
{
    unsigned char inputdata;
    inputdata = inb(0x60);
    return inputdata;
}



void keyboardHandler()
{
    unsigned char scancode;
    unsigned int shift_key = 0;

    canSend = 0;

    scancode = getScancode();
    if (scancode == 0x2A)
    {
        shift_key = 1;//Shift key is pressed
    }
    else if (scancode & 0xAA)
    {
        int shift_key = 0;//Shift Key is not pressed
    }

    if (scancode & 0x80)
    {
        int shiftaltctrl = 1;//Put anything to see what special keys were pressed
    }
    else
    {
        char character;
        if (scancode == 0x0F) {
            clicked = 0; // tab, resets stuff
            clearScreen();
        }

        if (scancode == 0x0e) {
            clicked = 0; // backspace
            vga_index--;
            print(" ", BLACK);
        }

        if (scancode == 0x01) {
            clicked = 0; // esc
        }

        if (scancode == 0x39 && clicked == 0) {
           
            character = ' '; // space
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x02 && clicked == 0) {
           
            character = '1';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x03 && clicked == 0) {
           
            character = '2';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x04 && clicked == 0) {
           
            character = '3';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x05 && clicked == 0) {
           
            character = '4';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x06 && clicked == 0) {
           
            character = '5';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x07 && clicked == 0) {
           
            character = '6';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x08 && clicked == 0) {
           
            character = '7';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x09 && clicked == 0) {
           
            character = '8';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x0A && clicked == 0) {
           
            character = '9';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x0B && clicked == 0) {
           
            character = '0';
            clicked = 1;
            canSend = 1;
           
        }

        if (scancode == 0x1E && clicked == 0) {
           
            character = 'a';
            clicked = 1;
            canSend = 1;
           
        }
        if (scancode == 0x30 && clicked == 0) {

            character = 'b';
            clicked = 1;
            canSend = 1;

        }
        if (scancode == 0x2E && clicked == 0) {

            character = 'c';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x20 && clicked == 0) {

            character = 'd';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x12 && clicked == 0) {

            character = 'e';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x21 && clicked == 0) {

            character = 'f';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x22 && clicked == 0) {

            character = 'g';
            clicked = 1;
            canSend = 1;
        }

        if (scancode == 0x23 && clicked == 0) {

            character = 'h';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x17 && clicked == 0) {

            character = 'i';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x24 && clicked == 0) {

            character = 'j';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x25 && clicked == 0) {

            character = 'k';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x26 && clicked == 0) {

            character = 'l';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x32 && clicked == 0) {

            character = 'm';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x31 && clicked == 0) {

            character = 'n';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x18 && clicked == 0) {

            character = 'o';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x19 && clicked == 0) {

            character = 'p';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x10 && clicked == 0) {

            character = 'q';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x13 && clicked == 0) {

            character = 'r';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x1F && clicked == 0) {

            character = 's';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x14 && clicked == 0) {

            character = 't';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x16 && clicked == 0) {

            character = 'u';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x2F && clicked == 0) {

            character = 'v';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x11 && clicked == 0) {

            character = 'w';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x2D && clicked == 0) {

            character = 'x';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x15 && clicked == 0) {

            character = 'y';
            clicked = 1;
            canSend = 1;
        }
        if (scancode == 0x2c && clicked == 0) {
            character = 'z';
            clicked = 1;
            canSend = 1;
        }

        if (canSend == 1) {
            vga_index += 10;
            printChar(character, WHITE);
            clicked = 0;
            canSend = 0;
        }
    }

}

void pause() {
    while(1) {
        unsigned char scancode;
        scancode = getScancode();
        if (scancode == 0x1C) {
            break;
        }
    }
}
#include "math.h"

void ifloor(int x) {
    int y = x % 10; // find last digit of integer
    while (y != 0) {
        y = x % 10;
        x--;
    }

}
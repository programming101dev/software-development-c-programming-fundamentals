#include <stdio.h>

int main(void) {
    unsigned int a = 12; // 1100 in binary
    unsigned int result = a << 2; // 110000 in binary

    printf("Bitwise Shift Left: %u\n", result); // Output: 48
    return 0;
}

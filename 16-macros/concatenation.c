#include <stdio.h>
#include <stdlib.h>

#define CONCAT(a, b) a##b

int main(void)
{
    const int CONCAT(num, ber) = 10;

    printf("%d\n", number);

    return EXIT_SUCCESS;
}

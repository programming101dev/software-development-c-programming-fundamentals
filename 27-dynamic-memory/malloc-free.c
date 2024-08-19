#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t size;
    int   *arr;

    size = 5;
    arr  = (int *)malloc(size * sizeof(int));

    for(size_t i = 0; i < size; i++)
    {
        arr[i] = (int)(i * 2);
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);

    return EXIT_SUCCESS;
}

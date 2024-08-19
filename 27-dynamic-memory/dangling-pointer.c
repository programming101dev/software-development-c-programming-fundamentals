#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t size = 5;
    int         *arr;
    int          exit_code;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        free(arr);
        // arr is now a dangling pointer

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wuse-after-free"
#endif
        // cppcheck-suppress deallocuse
        printf("%d\n", arr[0]);    // Undefined behavior    // NOLINT(clang-analyzer-unix.Malloc)
#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif
        exit_code = EXIT_SUCCESS;
    }

    return exit_code;
}

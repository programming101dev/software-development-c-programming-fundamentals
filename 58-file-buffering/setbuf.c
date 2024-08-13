#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buf[1024];  // User-allocated buffer
    setbuf(file, buf);

    fprintf(file, "This is a test.\n");  // Data will be buffered according to setbuf rules

    if (fclose(file) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

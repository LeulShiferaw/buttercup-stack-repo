#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int foo(char *str);

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size > 399)
        return 0;

    char *input = malloc(size + 1);
    if (!input)
        return 0;

    memcpy(input, data, size);
    input[size] = '\0';

    foo(input);

    free(input);
    return 0;
}

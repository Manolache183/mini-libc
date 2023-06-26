#include <stdio.h>
#include <string.h>

int puts(const char *str)
{
    size_t len = strlen(str);

    int r = write(1, str, len);
    
    if (r == -1)
        return r;

    return write(1, "\n", 1);
}


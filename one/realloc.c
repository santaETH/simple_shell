#include "shell.h"

char **_realloc(char **ptr, size_t old_size, size_t new_size)
{
    char **new_ptr = realloc(ptr, new_size);
    if (!new_ptr)
    {
        free(ptr);
        return NULL;
    }
    return new_ptr;
}


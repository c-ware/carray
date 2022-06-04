#ifndef CWARE_LIBCARRAY_COMMON_H
#define CWARE_LIBCARRAY_COMMON_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>

#include "../src/carray.h"

#define STRING_ARRAY_TYPE                   char*
#define STRING_ARRAY_HEAP                   1
#define STRING_ARRAY_FREE(value)            NULL
#define STRING_ARRAY_COMPARE(cmp_a, cmp_b)  (strcmp(cmp_a, cmp_b) == 0)

struct StringArray {
    int length;
    int capacity;
    char **contents;
};

#endif

#ifndef CWARE_LIBCARRAY_STACK_COMMON_H
#define CWARE_LIBCARRAY_STACK_COMMON_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>

#include "../src/carray.h"

#define STRING_ARRAY_S_TYPE                   char*
#define STRING_ARRAY_S_HEAP                   0
#define STRING_ARRAY_S_FREE(value)            NULL
#define STRING_ARRAY_S_COMPARE(cmp_a, cmp_b)  (strcmp(cmp_a, cmp_b) == 0)

struct StringArray {
    int length;
    int capacity;
    char **contents;
};

#endif

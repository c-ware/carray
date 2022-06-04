#include "stack_common.h"

int main(void) {
    char *strings[3] = {0};
    struct StringArray array = carray_init_stack(&array, strings, 3, STRING_ARRAY_S);

    carray_insert(&array, 0, "foo", STRING_ARRAY_S);
    assert(strcmp(array.contents[0], "foo") == 0);
    assert(array.length == 1);
    assert(array.capacity == 3);

    carray_insert(&array, 0, "bar", STRING_ARRAY_S);
    assert(strcmp(array.contents[0], "bar") == 0);
    assert(strcmp(array.contents[1], "foo") == 0);
    assert(array.length == 2);
    assert(array.capacity == 3);

    carray_insert(&array, 1, "baz", STRING_ARRAY_S);
    assert(strcmp(array.contents[0], "bar") == 0);
    assert(strcmp(array.contents[1], "baz") == 0);
    assert(strcmp(array.contents[2], "foo") == 0);
    assert(array.length == 3);
    assert(array.capacity == 3);

    return EXIT_SUCCESS; 
}

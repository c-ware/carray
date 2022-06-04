#include "stack_common.h"

int main(void) {
    char *strings[5];
    struct StringArray array = carray_init_stack(&array, strings, 5, STRING_ARRAY_S);

    carray_append(&array, "foo", STRING_ARRAY_S);
    assert(array.length == 1);
    assert(array.capacity == 5);
    assert(strcmp(array.contents[0], "foo") == 0);

    carray_append(&array, "bar", STRING_ARRAY_S);
    assert(array.length == 2);
    assert(array.capacity == 5);
    assert(strcmp(array.contents[0], "foo") == 0);
    assert(strcmp(array.contents[1], "bar") == 0);

    carray_append(&array, "baz", STRING_ARRAY_S);
    assert(array.length == 3);
    assert(array.capacity == 5);
    assert(strcmp(array.contents[0], "foo") == 0);
    assert(strcmp(array.contents[1], "bar") == 0);
    assert(strcmp(array.contents[2], "baz") == 0);

    carray_append(&array, "tuna", STRING_ARRAY_S);
    assert(array.length == 4);
    assert(array.capacity == 5);
    assert(strcmp(array.contents[0], "foo") == 0);
    assert(strcmp(array.contents[1], "bar") == 0);
    assert(strcmp(array.contents[2], "baz") == 0);
    assert(strcmp(array.contents[3], "tuna") == 0);

    carray_append(&array, "spam", STRING_ARRAY_S);
    assert(array.length == 5);
    assert(array.capacity == 5);
    assert(strcmp(array.contents[0], "foo") == 0);
    assert(strcmp(array.contents[1], "bar") == 0);
    assert(strcmp(array.contents[2], "baz") == 0);
    assert(strcmp(array.contents[3], "tuna") == 0);
    assert(strcmp(array.contents[4], "spam") == 0);

    return EXIT_SUCCESS;
}

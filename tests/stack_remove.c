#include "stack_common.h"

int main(void) {
    char *string[5] = {0};
    struct StringArray array = carray_init_stack(&array, string, 5, STRING_ARRAY_S);

    carray_insert(&array, 0, "foo", STRING_ARRAY_S);
    carray_insert(&array, 1, "bar", STRING_ARRAY_S);
    carray_insert(&array, 2, "baz", STRING_ARRAY_S);
    carray_insert(&array, 3, "tuna", STRING_ARRAY_S);
    carray_insert(&array, 4, "spam", STRING_ARRAY_S);

    assert(array.length == 5);
    assert(strcmp(array.contents[0], "foo") == 0);
    assert(strcmp(array.contents[1], "bar") == 0);
    assert(strcmp(array.contents[2], "baz") == 0);
    assert(strcmp(array.contents[3], "tuna") == 0);
    assert(strcmp(array.contents[4], "spam") == 0);
    
    carray_remove(&array,  "foo", STRING_ARRAY_S);
    assert(array.length == 4);
    assert(strcmp(array.contents[0], "bar") == 0);
    assert(strcmp(array.contents[1], "baz") == 0);
    assert(strcmp(array.contents[2], "tuna") == 0);
    assert(strcmp(array.contents[3], "spam") == 0);

    carray_remove(&array,  "tuna", STRING_ARRAY_S);
    assert(array.length == 3);
    assert(strcmp(array.contents[0], "bar") == 0);
    assert(strcmp(array.contents[1], "baz") == 0);
    assert(strcmp(array.contents[2], "spam") == 0);

    carray_remove(&array,  "bar", STRING_ARRAY_S);
    assert(array.length == 2);
    assert(strcmp(array.contents[0], "baz") == 0);
    assert(strcmp(array.contents[1], "spam") == 0);

    carray_remove(&array,  "spam", STRING_ARRAY_S);
    assert(array.length == 1);
    assert(strcmp(array.contents[0], "baz") == 0);

    carray_remove(&array,  "baz", STRING_ARRAY_S);
    assert(array.length == 0);

    return EXIT_SUCCESS;
}

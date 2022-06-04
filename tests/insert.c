#include "common.h"

int main(void) {
    struct StringArray *array = carray_init(array, STRING_ARRAY);

    carray_insert(array, 0, "foo", STRING_ARRAY);
    assert(strcmp(array->contents[0], "foo") == 0);
    assert(array->length == 1);
    assert(array->capacity == 5);

    carray_insert(array, 0, "bar", STRING_ARRAY);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "foo") == 0);
    assert(array->length == 2);
    assert(array->capacity == 5);

    carray_insert(array, 1, "baz", STRING_ARRAY);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "baz") == 0);
    assert(strcmp(array->contents[2], "foo") == 0);
    assert(array->length == 3);
    assert(array->capacity == 5);

    carray_insert(array, 2, "thud", STRING_ARRAY);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "baz") == 0);
    assert(strcmp(array->contents[2], "thud") == 0);
    assert(strcmp(array->contents[3], "foo") == 0);
    assert(array->length == 4);
    assert(array->capacity == 5);

    carray_insert(array, 1, "spam", STRING_ARRAY);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "spam") == 0);
    assert(strcmp(array->contents[2], "baz") == 0);
    assert(strcmp(array->contents[3], "thud") == 0);
    assert(strcmp(array->contents[4], "foo") == 0);
    assert(array->length == 5);
    assert(array->capacity == 5);

    carray_insert(array, 2, "tuna", STRING_ARRAY);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "spam") == 0);
    assert(strcmp(array->contents[2], "tuna") == 0);
    assert(strcmp(array->contents[3], "baz") == 0);
    assert(strcmp(array->contents[4], "thud") == 0);
    assert(strcmp(array->contents[5], "foo") == 0);
    assert(array->length == 6);
    assert(array->capacity == 10);

    carray_free(array, STRING_ARRAY);

    return EXIT_SUCCESS;
}

#include "common.h"

int main(void) {
    char *string = NULL;
    struct StringArray *array = carray_init(array, STRING_ARRAY);

    carray_insert(array, 0, "foo", STRING_ARRAY);
    carray_insert(array, 1, "bar", STRING_ARRAY);
    carray_insert(array, 2, "baz", STRING_ARRAY);
    carray_insert(array, 3, "tuna", STRING_ARRAY);
    carray_insert(array, 4, "spam", STRING_ARRAY);

    assert(string == NULL);

    string = carray_pop(array, 0, string);
    assert(strcmp(string, "foo") == 0);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "baz") == 0);
    assert(strcmp(array->contents[2], "tuna") == 0);
    assert(strcmp(array->contents[3], "spam") == 0);
    assert(array->length == 4);
    assert(array->capacity == CARRAY_INITIAL_SIZE);

    string = carray_pop(array, 3, string);
    assert(strcmp(string, "spam") == 0);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "baz") == 0);
    assert(strcmp(array->contents[2], "tuna") == 0);
    assert(array->length == 3);
    assert(array->capacity == CARRAY_INITIAL_SIZE);

    string = carray_pop(array, 1, string);
    assert(strcmp(string, "baz") == 0);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "tuna") == 0);
    assert(array->length == 2);
    assert(array->capacity == CARRAY_INITIAL_SIZE);

    string = carray_pop(array, 1, string);
    assert(strcmp(string, "tuna") == 0);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(array->length == 1);
    assert(array->capacity == CARRAY_INITIAL_SIZE);

    string = carray_pop(array, 0, string);
    assert(strcmp(string, "bar") == 0);
    assert(array->length == 0);
    assert(array->capacity == CARRAY_INITIAL_SIZE);

    carray_free(array, STRING_ARRAY);

    return EXIT_SUCCESS;
}

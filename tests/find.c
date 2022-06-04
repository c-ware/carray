#include "common.h"

int main(void) {
    int index = 0;
    struct StringArray *array = carray_init(array, STRING_ARRAY);

    index = carray_find(array, "foo", index, STRING_ARRAY);
    assert(index == -1);

    carray_insert(array, 0, "foo", STRING_ARRAY);
    index = carray_find(array, "foo", index, STRING_ARRAY);
    assert(index == 0);

    carray_insert(array, 1, "bar", STRING_ARRAY);
    index = carray_find(array, "bar", index, STRING_ARRAY);
    assert(index == 1);

    carray_insert(array, 2, "tuna", STRING_ARRAY);
    index = carray_find(array, "tuna", index, STRING_ARRAY);
    assert(index == 2);

    carray_insert(array, 1, "spam", STRING_ARRAY);
    index = carray_find(array, "spam", index, STRING_ARRAY);
    assert(index == 1);

    index = carray_find(array, "thud", index, STRING_ARRAY);
    assert(index == -1);

    carray_free(array, STRING_ARRAY);

    return EXIT_SUCCESS;
}

#include "stack_common.h"

int main(void) {
    int index = 0;
    char *strings[10] = {0};
    struct StringArray array = carray_init_stack(&array, strings, 10, STRING_ARRAY_S);

    index = carray_find(&array, "foo", index, STRING_ARRAY_S);
    assert(index == -1);

    carray_insert(&array, 0, "foo", STRING_ARRAY_S);
    index = carray_find(&array, "foo", index, STRING_ARRAY_S);
    assert(index == 0);

    carray_insert(&array, 1, "bar", STRING_ARRAY_S);
    index = carray_find(&array, "bar", index, STRING_ARRAY_S);
    assert(index == 1);

    carray_insert(&array, 2, "tuna", STRING_ARRAY_S);
    index = carray_find(&array, "tuna", index, STRING_ARRAY_S);
    assert(index == 2);

    carray_insert(&array, 1, "spam", STRING_ARRAY_S);
    index = carray_find(&array, "spam", index, STRING_ARRAY_S);
    assert(index == 1);

    index = carray_find(&array, "thud", index, STRING_ARRAY_S);
    assert(index == -1);

    return EXIT_SUCCESS;
}

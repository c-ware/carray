#include "common.h"

int main(void) {
    struct StringArray *array = carray_init(array, STRING_ARRAY);
    
    assert(array->length == 0);
    assert(array->capacity == CARRAY_INITIAL_SIZE);
    assert(array->contents != NULL);

    carray_free(array, STRING_ARRAY);

    return EXIT_SUCCESS;
}

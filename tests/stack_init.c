#include "stack_common.h"

int main(void) {
    char *strings[10] = {0};
    struct StringArray array = carray_init_stack(&array, strings, 10, STRING_ARRAY_S);
    
    assert(array.length == 0);
    assert(array.capacity == 10);
    assert(array.contents == strings);

    return EXIT_SUCCESS;
}

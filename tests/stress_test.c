/*
 * A stress test for the dynamic array. Appends 100 elements
 * into the array.
*/

#include "common.h"

int main(void) {
    int index = 0;
    struct StringArray *new_array = carray_init(new_array, STRING_ARRAY);

    char *strings[100] = {
        "mjh", "exc", "yqq", "wjr", "hal", "ttc", "vkr", "ush", "nnl", "vrd",
        "iqw", "nlp", "maz", "xbn", "ipi", "mud", "pbu", "lgv", "qmd", "hjh",
        "vsv", "kyp", "sft", "gxv", "xsw", "mzu", "bfb", "wpv", "nan", "ezz",
        "rrt", "mnp", "ies", "vpk", "xuq", "peu", "hjj", "hii", "ibc", "tvi",
        "cld", "uqv", "nff", "rrm", "jbw", "cjn", "thw", "rmn", "tlk", "bmb",
        "pdx", "pax", "ksw", "ufc", "lgm", "fwt", "ngu", "unc", "teh", "uda",
        "yrj", "gjp", "wom", "jqi", "vld", "rxs", "lmn", "aff", "ogh", "cle",
        "yvi", "ftl", "ypb", "qcg", "lpy", "erc", "frr", "whm", "atq", "jti",
        "byc", "ybl", "rkx", "sdm", "qnf", "iuw", "lri", "fui", "usg", "xjh",
        "ezq", "beq", "kzu", "ezj", "bhj", "dgv", "wez", "pjr", "kvl", "egh",
    };

    /* Append values */
    for(index = 0; index < 100; index++) {
        carray_append(new_array, strings[index], STRING_ARRAY);
    }

    /* Read */
    for(index = 0; index < 100; index++) {
        assert(strcmp(new_array->contents[index], strings[index]) == 0);
    }

    carray_free(new_array, STRING_ARRAY);

    return EXIT_SUCCESS;
}

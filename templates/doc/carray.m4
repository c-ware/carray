## Macros used in the documentation generation.

define(`CARRAY_HEADER', `
.TH "CWARE_MANUAL_NAME" "cware" "March 8th, 2022" "" \
    "C-Ware Manual"
')

## $1: the name of the macro
define(`CARRAY_EXAMPLE_COMMENT', `
/*
 * This example showcases how to use the
.B $1
macro.
.br
*/
')

## The information like struct definitions and
## $1: value of the heap definition
define(`CARRAY_EXAMPLE_INFO', `
.TS
tab(;);
l l
.
#define STRING_ARRAY_TYPE;char*
#define STRING_ARRAY_HEAP;$1
#define STRING_ARRAY_FREE(value);NULL
#define STRING_ARRAY_COMPARE(cmp_a, cmp_b);(strcmp(cmp_a, cmp_b) == 0)
.TE

struct StringArray {
    int length;
    int capacity;
    char **contents;
.br
};
')

## Dump the inclusions used by the library
define(`CARRAY_INCLUSIONS', `
.B #include <stdio.h>
.br
.B #include <stdlib.h>
.br
.B #include <string.h>
.br
.B #include <cware/carray/carray.h>
.br
')

## Format a parameter description
## $1: the name of the parameter
## $2: the description of the parameter
define(`CARRAY_PARAMETER', `.I $1
will be $2
.br')

define(`CARRAY_SEE_ALSO', `
.BR cware (cware),
.BR carray (cware)
')

## Error list macros

define(`CARRAY_ERROR_LIST_START', `
This macro will print an error message to the stderr, and exit the program when
any of the following conditions are met:
.RS
')

## Define a possible error condition
## $1: the error condition
define(`CARRAY_ERROR_COND', `
.IP \[bu] 0.4i
$1
.br
')

define(`CARRAY_ERROR_LIST_END', `
.RE
')

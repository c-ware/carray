/* c-ware carray SPEED CHECK */

#define CARRAY_RESIZE(size) \
    ((size) + 50)

#include <time.h>
#include "common.h"

#define LIMIT 100000 /* How many iterations to run */

int i;
char** strings;

struct StringArray* new_array;

char charset[] = "0123456789"
	"abcdefghijklmnopqrstuvwxyz"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void rand_str(char* dest, size_t length) {
	while(length-- > 0) {
		size_t pos = (double) rand() / RAND_MAX * (sizeof charset - 1);
		*dest++ = charset[pos];
	}
	*dest = '\0';
}

int main() {
    clock_t start, end;
    double runtime;

    printf("Sizing memory...\n");
    strings = malloc(sizeof(char*) * LIMIT);
    for(i = 0; i < LIMIT; i++) {
        strings[i] = malloc(16);
    }

	printf("Generating strings...\n");

	for(i = 0; i < LIMIT; i++) {
		rand_str(strings[i], 16);
	}

	printf("Execution begins...\n");

	start = clock();

	new_array = carray_init(new_array, STRING_ARRAY);

	for(i = 0; i < LIMIT; i++) {
		carray_append(new_array, strings[i], STRING_ARRAY);
	}

	carray_free(new_array, STRING_ARRAY);

    end = clock();
    
    for(i = 0; i < LIMIT; i++) {
        free(strings[i]);
    }
    free(strings);

	runtime = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time: %f\n", runtime);

    fgetc(stdin);
	return 0;
}

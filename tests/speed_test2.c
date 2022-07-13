/* c-ware carray SPEED CHECK */

#include <time.h>
#include "common.h"

#define LIMIT 10000000 /* How many iterations to run */

int i;
char strings[LIMIT][16];
clock_t start, end;
double runtime;
struct StringArray* new_array;
char charset[] = "0123456789"
	"abcdefghijklmnopqrstuvwxyz"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void rand_str(register char* dest, register size_t length) {
	while(length-- > 0) {
		register size_t pos = (double) rand() / RAND_MAX * (sizeof charset - 1);
		*dest++ = charset[pos];
	}
	*dest = '\0';
}

int main() {
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

	runtime = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time: %f\n", runtime);
	return 0;
}

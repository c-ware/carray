# This Makefile is the output of a template Makefile that was
# processed by the m4 macro preprocessor. It is not intended
# to be human readable.

CC=cc
PREFIX=/usr/local
CFLAGS=-ansi -Wall -Wextra -Wshadow -Wdouble-promotion -fpic -Wno-unused-variable -Wno-unused-function
TESTS=tests//stack_pop.out tests//stress_test.out tests//stack_append.out tests//pop.out tests//stack_init.out tests//insert.out tests//init.out tests//stack_insert.out tests//extreme_stress.out tests//append.out tests//stack_remove.out tests//stack_find.out tests//remove.out tests//find.out 
DOCS=./doc/carray_find.cware ./doc/carray_free.cware ./doc/carray_append.cware ./doc/carray_init.cware ./doc/carray_insert.cware ./doc/carray_is_empty.cware ./doc/carray_pop.cware ./doc/carray.cware ./doc/carray_length.cware ./doc/carray_remove.cware ./doc/carray_init_stack.cware 
MANNAMES=carray_find.cware carray_free.cware carray_append.cware carray_init.cware carray_insert.cware carray_is_empty.cware carray_pop.cware carray.cware carray_length.cware carray_remove.cware carray_init_stack.cware 
DEBUGGER=

.PHONY: all clean check install
.SUFFIXES: .c .out

all: $(TESTS) $(DOCS)

clean:
	rm -f $(TESTS)

check:
	./scripts/check.sh $(DEBUGGER)

install:
	cp $(DOCS) $(PREFIX)/share/man/mancware

uninstall:
	for manual in $(MANNAMES); do  \
		rm -f $(PREFIX)/share/man/mancware/$$manual; \
	done

.c.out:
	$(CC) $< $(OBJS) $(CFLAGS) -o $@

# This Makefile is the output of a template Makefile that was
# processed by the m4 macro preprocessor. It is not intended
# to be human readable.

CC=cc
PREFIX=/usr/local
CFLAGS=-ansi -Wall -Wextra -Wshadow -Wdouble-promotion -fpic -Wno-unused-variable -Wno-unused-function
TESTS=syscmd(`find tests/ -type f -name "*.c" | tr "\n" " " | sed "s/\.c/.out/g"')
DOCS=syscmd(`find . -type f -name "*.cware" | tr "\n" " "')
MANNAMES=syscmd(`for src in $(find . -type f -name "*.cware"); do echo $src | xargs basename; done | tr "\n" " "')
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

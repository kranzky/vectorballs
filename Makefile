# vim: syntax=make:noet

GCC := gcc -g -Wall -O3
LDD := -framework SDL2 -framework SDL2_image

TARGETS := bin/vectorballs
SOURCES := $(filter-out $(TARGETS:bin/%=src/%.c),$(wildcard src/*.c))
HEADERS := $(wildcard include/*.h)
OBJECTS := $(SOURCES:src/%.c=object/%.o)

all: ${OBJECTS} ${TARGETS}

clean:
	@echo "Cleaning up"
	-@rm -f ${OBJECTS} $(TARGETS:%=object/%.o) ${TARGETS}

grind: ${TARGETS}
	-@valgrind --dsymutil=yes --leak-check=full --track-origins=yes ${TARGETS}

object/%.o: src/%.c ${HEADERS}
	@echo "Compiling $<"
	@${GCC} -Iinclude -c $< -o $@

bin/%: object/%.o ${OBJECTS}
	@echo "Linking $@"
	${GCC} -o $@ ${OBJECTS} $< ${LDD}

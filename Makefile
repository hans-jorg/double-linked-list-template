#
# @file   Makefile
# @author Hans
#

PROGNAME=test-linked-list

CFLAGS+=-g
CFLAGS+= -DTEST
CFLAGS+= -DDEBUG
LIBS+= -lm

# Source files
SRCS=linked-list.c test-linked-list.c

# Object files
OBJS=$(SRCS:.c=.o)


default: build

build: $(PROGNAME)

$(PROGNAME): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(LFLAGS) $^ $(LIBS)

run: $(PROGNAME)
	./$(PROGNAME)

clean:
	rm -rf *.o $(PROGNAME)

edit:
	gedit *.c *.h Makefile &

.phony: clean run

# Extra dependencies
linked-list.o: linked-list.h  linked-list-template.h
test-linked-list.o: linked-list.h linked-list-template.h

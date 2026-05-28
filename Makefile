##
# CPU-Cache-Simulator
#
# @file
# @version 0.1

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = src/tools.o

all: tests/test_address_parse
tests/test_address_parse: tests/test_address_parse.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: tests/test_address_parse
	./tests/test_address_parse

clean:
	rm -f src/*.o tests/*.o tests/test_address_parse
# end

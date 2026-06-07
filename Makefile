##
# CPU-Cache-Simulator
#
# @file
# @version 0.1

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS1 = src/tools.o
OBJS2 = src/memory.o

all: tests/test_address_parse tests/test_memory
tests/test_address_parse: tests/test_address_parse.o $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

tests/test_memory: tests/test_memory.o $(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: tests/test_address_parse tests/test_memory
	./tests/test_address_parse
	./tests/test_memory


clean:
	rm -f src/*.o tests/*.o tests/test_address_parse tests/test_memory
# end

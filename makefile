all: test_int.out test_double.out

CC=g++
CPPFLAGS=-std=c++11 -Wall

test_int.out: test_int.cpp memo_map.hpp
	$(CC) $(CPPFLAGS) $< -o $@

test_double.out: test_double.cpp memo_map.hpp
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f test_int.out test_double.out

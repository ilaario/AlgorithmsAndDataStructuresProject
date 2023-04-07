CC = gcc
GFLAGS = -o0 -Wall -Wextra -Werror -Wpedantic

run_string:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	./build/main_ex1.out records.csv sorted.csv 90 1

run_int:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	./build/main_ex1.out records.csv sorted.csv 90 2

run_float:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	./build/main_ex1.out records.csv sorted.csv 90 3

valgrind:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/main_ex1.out records.csv NULL

run_gflags:
	$(CC) $(GFLAGS) main_ex1.c -o build/main_ex1
	./build/main_ex1 records.csv NULL


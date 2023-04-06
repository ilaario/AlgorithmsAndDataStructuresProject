CC = gcc
GFLAGS = -o3 -Wall -Wextra -Werror -Wpedantic -std=c99

run:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	./build/main_ex1.out records.csv NULL 90

valgrind:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/main_ex1.out records.csv NULL

run_gflags:
	$(CC) $(GFLAGS) main_ex1.c -o build/main_ex1
	./build/main_ex1 records.csv NULL


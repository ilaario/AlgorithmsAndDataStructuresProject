CC = gcc
GFLAGS = -o3 -Wall -Wextra -Werror -Wpedantic -std=c99

run:
	$(CC) main_ex1.c -o build/main_ex1
	./build/main_ex1 records.csv NULL
run_gflags:
	$(CC) $(GFLAGS) main_ex1.c -o build/main_ex1
	./build/main_ex1 records.csv NULL


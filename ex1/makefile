CC = gcc
GFLAGS = -Ofast -Wall -Wpedantic -Wextra 
K ?= 25
TYPE ?= 2

run:
	mkdir -p build
	$(CC) src/main_ex1.c src/ex1_sort.c src/utilities.c -o build/main_ex1.out 
	./build/main_ex1.out input/records.csv output/sorted.csv $(K) $(TYPE)

valgrind:
	mkdir -p build
	$(CC) src/main_ex1.c src/ex1_sort.c src/utilities.c -o build/main_ex1.out 
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/main_ex1.out input/records.csv output/sorted.csv $(K) $(TYPE)

run_gflags:
	$(CC) $(GFLAGS) src/main_ex1.c src/ex1_sort.c src/utilities.c -o build/main_ex1.out
	./build/main_ex1 input/records.csv output/sorted.csv $(K) $(TYPE) run

run_unityTest:
	mkdir -p build
	$(CC) src/ex1_unityTest.c src/unity.c src/ex1_sort.c src/utilities.c -o build/testUnity_ex1.out
	./build/testUnity_ex1.out

clear:
	rm -rf build


CC = gcc
GFLAGS = -g -Wall
TEST ?= 1

run:
	mkdir -p build
	$(CC) $(GFLAGS) src/ex2.c src/SkipList.c -o build/main_ex2.out
	./build/main_ex2.out input/dictionary.txt input/correctme.txt $(TEST)

clear:
	rm -rf build
	clear
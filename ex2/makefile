CC = gcc
GFLAGS = -g -Wall
TEST ?= 20

run:
	mkdir -p build
	$(CC) $(GFLAGS) src/ex2.c src/SkipList.c -o build/main_ex2.out
	./build/main_ex2.out input/dictionary.txt input/correctme.txt $(TEST)

valgrind:
	mkdir -p build
	$(CC) src/ex2.c src/SkipList.c -o build/ex2.out 
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/ex2.out input/dictionary.txt input/correctme.txt $(TEST)
	
run_unity:
	mkdir -p build
	$(CC) $(GFLAGS) src/ex2_unityTest.c src/SkipList.c src/unity.c -o build/unity_ex2.out
	./build/unity_ex2.out

clear:
	rm -rf build
CC = gcc
GFLAGS = -Ofast -Wall -Wpedantic

run_string:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	./build/main_ex1.out records.csv sorted.csv 45 1 run

run_int:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	./build/main_ex1.out records.csv sorted.csv 90 2 run

run_float:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out
	./build/main_ex1.out records.csv sorted.csv 90 3 run

valgrind_string:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out 
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/main_ex1.out records.csv sorted.csv 90 1

valgrind_int:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out 
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/main_ex1.out records.csv sorted.csv 90 2

valgrind_float:
	mkdir -p build
	$(CC) main_ex1.c -o build/main_ex1.out 
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/main_ex1.out records.csv sorted.csv 90 3

run_test:
	mkdir -p build
	$(CC) main_ex1.c -o build/test_ex1.out
	./build/test_ex1.out records.csv perfStr.csv perfInt.csv perfFloat.csv test

valgrind_test:
	mkdir -p build
	$(CC) main_ex1.c -o build/test_ex1.out 
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/test_ex1.out records.csv perfStr.csv perfInt.csv perfFloat.csv test

run_gflagsInt:
	$(CC) $(GFLAGS) main_ex1.c -o build/main_ex1
	./build/main_ex1 records.csv sorted.csv 25 2 run

run_gflagsString:
	$(CC) $(GFLAGS) main_ex1.c -o build/main_ex1
	./build/main_ex1 records.csv sorted.csv 25 1 run

run_gflagsFloat:
	$(CC) $(GFLAGS) main_ex1.c -o build/main_ex1
	./build/main_ex1 records.csv sorted.csv 25 3 run

clear:
	rm -rf build


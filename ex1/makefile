CC = gcc
GFLAGS = -Ofast -Wall -Wpedantic -Wextra -Werror -Wfatal-errors -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long -Wuninitialized -Wconversion -Wstrict-overflow=5 -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wswitch-default -Wswitch-enum -Wunreachable-code -Winit-self -Wstrict-aliasing=2 -Wold-style-definition -Wmissing-include-dirs -Wno-unused-parameter -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-sign-compare -Wno-variadic-macros -Wno-parentheses -Wno-missing-braces -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-sign-compare -Wno-variadic-macros -Wno-parentheses -Wno-missing-braces -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-sign-compare -Wno-variadic-macros -Wno-parentheses -Wno-missing-braces -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-sign-compare -Wno-variadic-macros -Wno-parentheses -Wno-missing-braces -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-sign-compare -Wno-variadic-macros -Wno-parentheses -Wno-missing-braces -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-sign-compare -Wno-variadic-macros -Wno-parentheses -Wno-missing-braces -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-sign-compare -Wno-variadic-macros -Wno-paren
K ?= 25
TYPE ?= 2

run:
	mkdir -p build
	$(CC) src/main_ex1.c src/ex1_sort.c -o build/main_ex1.out
	./build/main_ex1.out input/records.csv output/sorted.csv $(K) $(TYPE)

valgrind:
	mkdir -p build
	$(CC) src/main_ex1.c src/ex1_sort.c -o build/main_ex1.out 
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./build/main_ex1.out input/records.csv output/sorted.csv $(K) $(TYPE)

run_gflags:
	$(CC) $(GFLAGS) src/main_ex1.c src/ex1_sort.c -o build/main_ex1.out
	./build/main_ex1 input/records.csv output/sorted.csv $(K) $(TYPE) run

run_unityTest:
	mkdir -p build
	$(CC) src/ex1_unityTest.c src/unity.c src/ex1_sort.c -o build/testUnity_ex1.out
	./build/testUnity_ex1.out

clear:
	rm -rf build
	clear


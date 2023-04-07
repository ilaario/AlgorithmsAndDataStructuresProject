#ifndef EX_1_TEST_H
#define EX_1_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

void testPerf(const char *input, const char *output_string, const char *output_int, const char *output_float);
void printResult(int type, int i, const char *output, double time_spent);

#endif
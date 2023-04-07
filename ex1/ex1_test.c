#include "main_ex1.h"

void testPerf(const char *input, const char *output_string, const char *output_int, const char *output_float){
    struct record *a = read_array(input);

    printf("Testing performance of sorting with string with different values of k\n");
    FILE *fp = fopen(output_string, "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type \t K \t\t Time \n");
    
    for(int i = 0; i <= 500; i++){
        struct record *str_a = malloc(sizeof(struct record) * length_array);
        memcpy(str_a, a, sizeof(struct record) * length_array);
        printf("Sorting with i = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(str_a, length_array, sizeof(struct record), i, compare_string);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d \t\t %d \t\t %f\n", 1, i, time_spent);
        free(str_a);
    }
    printf("Sorting with string done.\n");
    fclose(fp);


    printf("Testing performance of sorting with int with different values of k\n");
    fp = fopen(output_int, "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type \t K \t\t Time \n");
    for(int i = 0; i <= 500; i++){
        struct record *int_a = malloc(sizeof(struct record) * length_array);
        memcpy(int_a, a, sizeof(struct record) * length_array);
        printf("Sorting with i = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(int_a, length_array, sizeof(struct record), i, compare_int);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d \t\t %d \t\t %f\n", 2, i, time_spent);
        free(int_a);
    }
    printf("Sorting with int done.\n");
    fclose(fp);

    printf("Testing performance of sorting with float with different values of k\n");
    fp = fopen(output_float, "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type \t K \t\t Time \n");
    for(int i = 0; i <= 500; i++){
        struct record *float_a = malloc(sizeof(struct record) * length_array);
        memcpy(float_a, a, sizeof(struct record) * length_array);
        printf("Sorting with i = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(float_a, length_array, sizeof(struct record), i, compare_float);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d \t\t %d \t\t %f\n", 3, i, time_spent);
        free(float_a);
    }
    printf("Sorting with float done.\n");
    fclose(fp);

    printf("Done testing!\n");
    destroy_Rarr(a);
}

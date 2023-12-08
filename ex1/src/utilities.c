#include "utilities.h"

struct record* read_array(FILE* fp){
    clock_t begin_read = clock();
    unsigned int i = 0;
    char *read_line_p, *string_tmp, buffer[1024];
    int buff_size = 1024;
    struct record *array_to_sort;
    length_array = 1000;

    printf("Reading data from file\n");

    if(fp == NULL){
        fprintf(stderr, "main: Error opening file\n");
        exit(EXIT_FAILURE);
    }
    array_to_sort = malloc(length_array * sizeof(struct record));

    while ((fgets(buffer, buff_size, fp) != NULL) && (i < STOP_COUNT)){
        if(length_array == i){
            length_array *= 2;
            array_to_sort = realloc(array_to_sort, length_array * sizeof(struct record));
        }
        read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
        if(read_line_p == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(read_line_p, buffer);
        array_to_sort[i].id = atoi(strtok(read_line_p, ","));
        string_tmp = strtok(NULL, ",");
        char* str = malloc((strlen(string_tmp) + 1) * sizeof(char));
        strcpy(str, string_tmp);
        array_to_sort[i].str_f = str;
        array_to_sort[i].int_f = atoi(strtok(NULL, ","));
        array_to_sort[i].float_f = atof(strtok(NULL, ","));
        i++;
        free(read_line_p);
    }
    fclose(fp);
    length_array = (unsigned int) i;
    clock_t end_read = clock();
    double time_spent_read = (double)(end_read - begin_read) / CLOCKS_PER_SEC;
    printf("Read of the file ended, allocated %d records, reading time = %fs\n", length_array, time_spent_read);
    return array_to_sort;
}

int destroy_Rarr(struct record *ga){
    if(ga == NULL){
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < length_array; i++){
        free(ga[i].str_f);
    }
    
    free(ga);
    return 1;
}

void print_array(struct record *a, FILE* fp){
    printf("Printing array to file, please wait...\n");
    clock_t start = clock();
    if(fp == NULL){
        fprintf(stderr, "Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "id, str_f, int_f, float_f\n");
    for(int i=0;i<length_array;i++){
        fprintf(fp, "%d, %s, %d, %f\n", a[i].id, a[i].str_f, a[i].int_f, a[i].float_f);
    }
    fclose(fp);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Done in %fs!\n", time_spent);
}
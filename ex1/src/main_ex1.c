#include "main_ex1.h"

void sort_records(FILE *infile, FILE *outfile, size_t k, size_t field);

int main(int argc, char *argv[]){
    if(argc < 4){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    }

    int field = atoi(argv[4]);

    if(field == 0){
        testPerf(fopen(argv[1], "r"));
    } else if (field == 1){
        sort_records(fopen(argv[1], "r"), fopen(argv[2], "w"), atoi(argv[3]), sizeof(char*));
    } else if (field == 2){
        sort_records(fopen(argv[1], "r"), fopen(argv[2], "w"), atoi(argv[3]), sizeof(int));
    } else if (field == 3){
        sort_records(fopen(argv[1], "r"), fopen(argv[2], "w"), atoi(argv[3]), sizeof(double));
    } else {
        printf("main: Error, invalid field\n");
        exit(EXIT_FAILURE);
    }
}




// Function that implements the precedence relation between integers
int compare_int(const void* r1_p,const void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"compare_int: the first parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_int: the second parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    struct record *rec1_p = (struct record*)r1_p;
    struct record *rec2_p = (struct record*)r2_p;
    if(rec1_p->int_f > rec2_p->int_f){
        return(1);
    } else if(rec1_p->int_f < rec2_p->int_f){
        return(-1);
    }
    return(0);
}

// Function that implements the precedence relation between strings
int compare_string(const void* r1_p,const void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"compare_string: the first parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_string: the second parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    struct record *rec1_p = (struct record*)r1_p;
    struct record *rec2_p = (struct record*)r2_p;
    return(strcmp(rec1_p->str_f, rec2_p->str_f));
}



// Function that implements the precedence relation between float
int compare_float(const void* r1_p, const void* r2_p) {
    if(r1_p == NULL){
        fprintf(stderr,"compare_float: the first parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_float: the second parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    struct record *rec1_p = (struct record*)r1_p;
    struct record *rec2_p = (struct record*)r2_p;
    if (rec1_p->float_f <= rec2_p->float_f){
        return(1);
    }
    return(-1);
}

void testPerf(FILE *input){

    struct record *a = read_array(input);

    printf("Testing performance of sorting with string with different values of k\n");
    system("mkdir -p output");
    FILE *fp = fopen("output/perfStr.csv", "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type\tK\tTime\n");
    fflush(fp);
    for(int i = 0; i <= 250; i++){
        struct record *str_a = malloc(sizeof(struct record) * length_array);
        memcpy(str_a, a, sizeof(struct record) * length_array);
        printf("Sorting with k = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(str_a, length_array, sizeof(struct record), i, compare_string);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d\t%d\t%f\n", 1, i, time_spent);
        fflush(fp);
        free(str_a);
    }
    printf("Sorting with string done.\n");
    fclose(fp);


    printf("Testing performance of sorting with int with different values of k\n");
    fp = fopen("output/perfInt.csv", "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type\tK\tTime\n");
    fflush(fp);

    for(int i = 0; i <= 250; i++){
        struct record *int_a = malloc(sizeof(struct record) * length_array);
        memcpy(int_a, a, sizeof(struct record) * length_array);
        printf("Sorting with k = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(int_a, length_array, sizeof(struct record), i, compare_int);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d\t%d\t%f\n", 2, i, time_spent);
        fflush(fp);
        free(int_a);
    }
    printf("Sorting with int done.\n");
    fclose(fp);

    printf("Testing performance of sorting with float with different values of k\n");
    fp = fopen("output/perfFloat.csv", "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type\tK\tTime\n");
    fflush(fp);
    for(int i = 0; i <= 250; i++){
        struct record *float_a = malloc(sizeof(struct record) * length_array);
        memcpy(float_a, a, sizeof(struct record) * length_array);
        printf("Sorting with k = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(float_a, length_array, sizeof(struct record), i, compare_float);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d\t%d\t%f\n", 3, i, time_spent);
        fflush(fp);
        free(float_a);
    }
    printf("Sorting with float done.\n");
    fclose(fp);

    printf("Done testing!\n");
    destroy_Rarr(a);
}

void sort_records(FILE *infile, FILE *outfile, size_t k, size_t field){
    if(field == sizeof(int)){
        printf("\nMerge Binary Insertion Sort su Integers\n");
        struct record *read_int = read_array(infile);
        printf("Array before sorting:\n");
        printf("Array size: %u\n", length_array);
        printf("Sorting the Array...\n");
        clock_t begin = clock();
        merge_binary_insertion_sort(read_int, length_array, sizeof(struct record), k, compare_int);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        if(time_spent > 60){
            int min = time_spent / 60;
            int sec = time_spent - (min * 60);
            printf("Time spent ordering the int's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
        } else {
            printf("Time spent ordering the int's array: %fs\n", time_spent);
        }
        print_array(read_int, outfile);
        destroy_Rarr(read_int);
    } else if (field == sizeof(double)){
        printf("\n\nMerge Binary Insertion Sort su Floats\n");
        struct record *read_float = read_array(infile);
        printf("Array before sorting:\n");
        printf("Array size: %u\n", length_array);
        printf("Sorting the Array...\n");
        clock_t begin = clock();
        merge_binary_insertion_sort(read_float, length_array, sizeof(struct record), k, compare_float);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        if(time_spent > 60){
            int min = time_spent / 60;
            int sec = time_spent - (min * 60);
            printf("Time spent ordering the float's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
        } else {
            printf("Time spent ordering the float's array: %fs\n", time_spent);
        }
        print_array(read_float, outfile);
        destroy_Rarr(read_float);
    } else if(field == sizeof(char)) {
        printf("\n\nMerge Binary Insertion Sort su String\n");
        struct record *read_string = read_array(infile);
        printf("Array before sorting:\n");
        printf("Array size: %u\n", length_array);
        printf("Sorting the Array...\n");
        clock_t begin = clock();
        merge_binary_insertion_sort(read_string, length_array, sizeof(struct record), k, compare_string);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        if(time_spent > 60){
            int min = time_spent / 60;
            int sec = time_spent - (min * 60);
            printf("Time spent ordering the string's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
        } else {
            printf("Time spent ordering the string's array: %fs\n", time_spent);
        }
        print_array(read_string, outfile);
        destroy_Rarr(read_string);
    } else {
        printf("main: Error, wrong argument\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
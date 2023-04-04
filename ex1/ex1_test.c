#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "unity.h"
#include "main_ex1.h"

struct record {
    int identifier;
    char* string_field;
    int integer_field;
    double float_field;
};

static int* integer_array;
static char* s1 = "quanto";
static char* s2="Dianzi";
static char* s3="corpo";
static char* s4="tenuto";
static char* s5="guerra";
static char* s6="tanto";
static char* s7="pareva";
static char* s8="testimonio";
static char* s9="caccia.";
static char* s10="ferro";
static double* double_array;
static GenericArray *ordered_array_int;
static GenericArray *ordered_array_string;
static GenericArray *ordered_array_float;
static GenericArray *expected_array;

void setUp_unityTest(void) {
    int i, stopI = 1000;
    double stopD = 36.91;
    integer_array = malloc(10*sizeof(int*));
    double_array = malloc(10*sizeof(double*));
    srand(time(NULL));
    for(i=0; i<10; i++) {
        integer_array[i] = (int)(rand() % stopI);
        double_array[i] = (double)(rand() % stopI) / stopD;
    }
    ordered_array_int = newGenericArray();
    ordered_array_string = newGenericArray();
    ordered_array_float = newGenericArray();
    expected_array = newGenericArray();
}

void tearDown_unityTest(void) {
    free(integer_array);
    free(double_array);
    destroyGA(ordered_array_int);
    destroyGA(ordered_array_string);
    destroyGA(ordered_array_float);
    destroyGA(expected_array);
}

static void test_integer_ordered_array_is_empty_zero_elements(void){
    TEST_ASSERT_TRUE(sizeGA(ordered_array_int) == 0);
}

static void test_string_ordered_array_is_empty_one_element(void){
    struct record *record_p = malloc(sizeof(struct record));
    record_p->identifier = 0;
    record_p->string_field = s2;
    record_p->integer_field = integer_array[7];
    record_p->float_field = double_array[5];
    insertGA(ordered_array_string, (void*)record_p);
    TEST_ASSERT_FALSE(sizeGA(ordered_array_string) != 0);
}   

static void test_double_array_size_zero_elements(void){
    TEST_ASSERT_EQUAL_INT(0, sizeGA(ordered_array_float));
}

static void test_integer_array_size_two_elements(void){
    struct record *r1_p = malloc(sizeof(struct record));
    r1_p->identifier = 0;
    r1_p->string_field = s5;
    r1_p->integer_field = integer_array[3];
    r1_p->float_field = double_array[8];
    insertGA(ordered_array_int, (void*)r1_p);
    struct record *r2_p = malloc(sizeof(struct record));
    r2_p->identifier = 1;
    r2_p->string_field = s1;
    r2_p->integer_field = integer_array[4];
    r2_p->float_field = double_array[0];
    insertGA(ordered_array_int, (void*)r2_p);
    TEST_ASSERT_EQUAL_INT(2, sizeGA(ordered_array_int));
}

static void test_string_array_add_get_ten_elements(void) {
    struct record *rec1_p = malloc(sizeof(struct record));
    rec1_p->identifier = 0;
    rec1_p->string_field = s1;
    rec1_p->integer_field = integer_array[0];
    rec1_p->float_field = double_array[0];
    insertGA(ordered_array_string, (void*)rec1_p);

    struct record *rec2_p = malloc(sizeof(struct record));
    rec2_p->identifier = 1;
    rec2_p->string_field = s5;
    rec2_p->integer_field = integer_array[1];
    rec2_p->float_field = double_array[1];
    insertGA(ordered_array_string, (void*)rec2_p);
    
    struct record *rec3_p = malloc(sizeof(struct record));
    rec3_p->identifier = 2;
    rec3_p->string_field = s2;
    rec3_p->integer_field = integer_array[2];
    rec3_p->float_field = double_array[2];
    insertGA(ordered_array_string, (void*)rec3_p);

    struct record *rec4_p = malloc(sizeof(struct record));
    rec4_p->identifier = 3;
    rec4_p->string_field = s7;
    rec4_p->integer_field = integer_array[3];
    rec4_p->float_field = double_array[3];
    insertGA(ordered_array_string, (void*)rec4_p);
    
    struct record *rec5_p = malloc(sizeof(struct record));
    rec5_p->identifier = 4;
    rec5_p->string_field = s9;
    rec5_p->integer_field = integer_array[4];
    rec5_p->float_field = double_array[4];
    insertGA(ordered_array_string, (void*)rec5_p);

    struct record *rec6_p = malloc(sizeof(struct record));
    rec6_p->identifier = 5;
    rec6_p->string_field = s3;
    rec6_p->integer_field = integer_array[5];
    rec6_p->float_field = double_array[5];
    insertGA(ordered_array_string, (void*)rec6_p);

    struct record *rec7_p = malloc(sizeof(struct record));
    rec7_p->identifier = 6;
    rec7_p->string_field = s6;
    rec7_p->integer_field = integer_array[6];
    rec7_p->float_field = double_array[6];
    insertGA(ordered_array_string, (void*)rec7_p);

    struct record *rec8_p = malloc(sizeof(struct record));
    rec8_p->identifier = 7;
    rec8_p->string_field = s4;
    rec8_p->integer_field = integer_array[7];
    rec8_p->float_field = double_array[7];
    insertGA(ordered_array_string, (void*)rec8_p);
    
    struct record *rec9_p = malloc(sizeof(struct record));
    rec9_p->identifier = 8;
    rec9_p->string_field = s8;
    rec9_p->integer_field = integer_array[8];
    rec9_p->float_field = double_array[8];
    insertGA(ordered_array_string, (void*)rec9_p);

    struct record *rec10_p = malloc(sizeof(struct record));
    rec10_p->identifier = 9;
    rec10_p->string_field = s10;
    rec10_p->integer_field = integer_array[9];
    rec10_p->float_field = double_array[9];
    insertGA(ordered_array_string, (void*)rec10_p);

    insertionSort(ordered_array_string -> array, ordered_array_string -> n_el, sizeof(struct record), compare_string);

    insertGA(expected_array,(void*)rec5_p);
    insertGA(expected_array,(void*)rec6_p);
    insertGA(expected_array,(void*)rec3_p);
    insertGA(expected_array,(void*)rec10_p);
    insertGA(expected_array,(void*)rec2_p);
    insertGA(expected_array,(void*)rec4_p);
    insertGA(expected_array,(void*)rec1_p);
    insertGA(expected_array,(void*)rec7_p);
    insertGA(expected_array,(void*)rec8_p);
    insertGA(expected_array,(void*)rec9_p);


    TEST_ASSERT_EQUAL_PTR_ARRAY(ordered_array_string->array, expected_array->array, 10);
}


int test(void){
    // test session
    UNITY_BEGIN();
    RUN_TEST(test_integer_ordered_array_is_empty_zero_elements);
    RUN_TEST(test_string_ordered_array_is_empty_one_element);
    RUN_TEST(test_double_array_size_zero_elements);
    RUN_TEST(test_integer_array_size_two_elements);
    RUN_TEST(test_string_array_add_get_ten_elements);
    return UNITY_END();
}

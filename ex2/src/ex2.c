#include "SkipList.h"

#define IS_LETTER(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))

int compare(const void* v1, const void* v2) {
    if(v1 == NULL){
      fprintf(stderr,"precedes_string: the first parameter cannot be NULL \n");
      exit(EXIT_FAILURE);
    }
    if(v2 == NULL){
      fprintf(stderr,"precedes_string: the second parameter cannot be NULL \n");
      exit(EXIT_FAILURE);
    }
    char *word1 = (char *)v1;
    char *word2 = (char *)v2;
    if (strcasecmp(word1, word2) > 0)
      return 1;
    else if (strcasecmp(word1, word2) < 0)
      return -1;
    return 0;
}


void load_dictionary(struct SkipList* list, const char* file_name) {
    char* string;
    char buffer[1024];
    int buf_size = 1024;
    FILE* fp;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "main(load_dictionary): unable to open the file\n");
        exit(EXIT_FAILURE);
    }

    printf("Loading Dictionary...\n");

    clock_t t = clock();
    
    while (fgets(buffer, buf_size, fp) != NULL) {
        string = malloc((strlen(buffer)) * sizeof(char));
        if (string == NULL) {
            fprintf(stderr, "main(load_dictionary): unable to allocate memory for the string");
            exit(EXIT_FAILURE);
        }
        strncpy(string, buffer, strlen(buffer) - 1);
        // printf("%s\n", string);
        insert_skiplist(list, string);
    }
    t = clock() - t;

    printf("Dictionary Loaded Successfully!\n");
    printf("Execution time: %f s!\n", (((float)t) / CLOCKS_PER_SEC));

    fclose(fp);
}

void check_correctme(struct SkipList* list, const char* file_name) {
    char c;
    char string[35] = "";
    FILE* fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "main(load_dictionary): unable to open the file\n");
        exit(EXIT_FAILURE);
    }
    printf("\nWords to correct:\n");
    clock_t t = clock();
    while ((c = (char)fgetc(fp)) != EOF) {
        if (IS_LETTER(c)) {
            c = (char)tolower(c);
            strncat(string, &c, 1);
        } else if (c == ' ') {
            if (search_skiplist(list, string) == NULL) {
                printf("%s\n", string);
            }
            strcpy(string, "");
        }
    }
    if (search_skiplist(list, string) == NULL) {
        printf("%s\n", string);
    }
    strcpy(string, "");
    t = clock() - t;
    printf("Execution time: %f s!\n", (((float)t) / CLOCKS_PER_SEC));
    fclose(fp);
}

float check_correctme_test(struct SkipList* list, const char* file_name) {
    char c;
    char string[35] = "";
    FILE* fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "main(load_dictionary): unable to open the file\n");
        exit(EXIT_FAILURE);
    }
    printf("\nWords to correct:\n");
    clock_t t = clock();
    while ((c = (char)fgetc(fp)) != EOF) {
        if (IS_LETTER(c)) {
            c = (char)tolower(c);
            strncat(string, &c, 1);
        } else if (c == ' ') {
            if (search_skiplist(list, string) == NULL) {
                printf("%s\n", string);
            }
            strcpy(string, "");
        }
    }
    if (search_skiplist(list, string) == NULL) {
        printf("%s\n", string);
    }
    strcpy(string, "");
    t = clock() - t;
    printf("Execution time: %f s!\n", (((float)t) / CLOCKS_PER_SEC));
    fclose(fp);
    return (((float)t) / CLOCKS_PER_SEC);
}

void find_errors(const char* path1, const char* path2, size_t max_height) {
    struct SkipList* list;
    new_skiplist(&list, max_height, compare);
    if (list == NULL) {
        fprintf(stderr, "find_errors(): error while creating SkipList\n");
        exit(EXIT_FAILURE);
    }
    load_dictionary(list, path1);
    check_correctme(list, path2);
    clear_skiplist(&list);
}

void find_errors_test(const char* path1, const char* path2) {
    FILE *fp;
    system("mkdir -p test");
    fp = fopen("test/test.txt", "w");
    for (int i = 1; i < 100; i++){
        printf("Testing with max_height = %d\n", i);
        struct SkipList* list;
        new_skiplist(&list, i, compare);
        if (list == NULL) {
            fprintf(stderr, "find_errors(): error while creating SkipList\n");
            exit(EXIT_FAILURE);
        }
        load_dictionary(list, path1);
        float t = check_correctme_test(list, path2);
        printf("Time: %f\n", t);
        fprintf(fp, "%d %f\n", i, t);
        printf("------------------------------------------------\n");
        clear_skiplist(&list);
    }
    printf("Test completed!\n");
    fclose(fp);
}

int main(int argc, char** argv){

    if (argc < 4) {
        fprintf(stderr, "Usage: ./main_ex2 <dictionary.txt> <correctme.txt> <0 for test, x for different height>\n");
        exit(EXIT_FAILURE);
    }

    int max = atoi(argv[3]);

    if (max == 0) {
        printf("\nTesting max_height with different values...\n");
        find_errors_test(argv[1], argv[2]);
        return EXIT_SUCCESS;
    } else {
        printf("MAX_HEIGHT: %d\n", max);
        find_errors(argv[1], argv[2], max);
        return EXIT_SUCCESS;
    }
}
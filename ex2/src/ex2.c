#include "SkipList.h"

#define IS_LETTER(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))

int compare(void* v1, void* v2) {
    if (v1 == NULL) {
        fprintf(stderr, "compare: v1 must not be null\n");
        exit(EXIT_FAILURE);
    }
    if (v2 == NULL) {
        fprintf(stderr, "compare: v1 must not be null\n");
        exit(EXIT_FAILURE);
    }
    return strcmp((const char*)v1, (const char*)v2);
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

    printf("\nLoading Dictionary...\n");

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

    printf("\nDictionary Loaded Successfully!\n");
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
            if (search_skiplist(list, string) == -1) {
                printf("%s\n", string);
            }
            strcpy(string, "");
        }
    }

    if (search_skiplist(list, string) == -1) {
        printf("%s\n", string);
    }
    strcpy(string, "");

    t = clock() - t;
    printf("Execution time: %f s!\n", (((float)t) / CLOCKS_PER_SEC));

    fclose(fp);
}

void find_errors(const char* path1, const char* path2, size_t max_height) {
    struct SkipList* list;
    new_skiplist(list, max_height, compare);
    if (list == NULL) {
        fprintf(stderr, "find_errors(): error while creating SkipList\n");
        exit(EXIT_FAILURE);
    }

    load_dictionary(list, path1);

    // print_skip_list(list);

    check_correctme(list, path2);

    clear_skiplist(list);
}

int main(int argc, char** argv){
    struct SkipList *list;
    if (argc < 3) {
        fprintf(stderr, "Usage: ./main_ex2 <dictionary.txt> <correctme.txt>\n");
        exit(EXIT_FAILURE);
    }

    printf("\nMAX_HEIGHT: %d\n", MAX_HEIGHT);

    find_errors(argv[1], argv[2], MAX_HEIGHT);

    return EXIT_SUCCESS;
}

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);
long listMax(int n, int r, int c, int** o) {
    int i;
    long max=0;
    long* arr=(long*)calloc(n+2, sizeof(long));
    for(i=0;i<r;i++)
    {
        int left=o[i][0];
        int right=o[i][1]+1;
        int val=o[i][2];
        arr[left]+=val;
        arr[right]-=val;
    }
    long prev=0;
    for(i=0;i<n+2;i++)
    {
        arr[i]+=prev;
        prev=arr[i];
        max=max>arr[i] ? max : arr[i];
    }
    return max;
}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int operations_rows = parse_int(ltrim(rtrim(readline())));

    int operations_columns = parse_int(ltrim(rtrim(readline())));

    int** operations = malloc(operations_rows * sizeof(int*));

    for (int i = 0; i < operations_rows; i++) {
        *(operations + i) = malloc(operations_columns * (sizeof(int)));

        char** operations_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < operations_columns; j++) {
            int operations_item = parse_int(*(operations_item_temp + j));

            *(*(operations + i) + j) = operations_item;
        }
    }

    long result = listMax(n, operations_rows, operations_columns, operations);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

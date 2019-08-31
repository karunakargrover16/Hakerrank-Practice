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

int parse_int(char*);

int fun(void * ptr,void*ptr2)
{
    int * a=(int*)ptr;
    int * b=(int *)ptr2;
    return *a-*b;
}
int countPairs(int n, int* arr, int k) {
    qsort(arr,n,sizeof(int),fun);
    int i=0, j=0, ct=0;
    while(i<n && j<n)
    {
        while(arr[i]==arr[i+1])
            i++;
        while(arr[j]==arr[j+1])
            j++;
        if(arr[i]+k==arr[j])
        {
            i++;
            j++;
            ct++;
        }
        else if(arr[i]+k>arr[j])
        {
            j++;
        }
        else if(arr[i]+k<arr[j])
        {
            i++;
        }
    }
    return ct;
}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int numbers_count = parse_int(ltrim(rtrim(readline())));

    int* numbers = malloc(numbers_count * sizeof(int));

    for (int i = 0; i < numbers_count; i++) {
        int numbers_item = parse_int(ltrim(rtrim(readline())));

        *(numbers + i) = numbers_item;
    }

    int k = parse_int(ltrim(rtrim(readline())));

    int result = countPairs(numbers_count, numbers, k);

    fprintf(fptr, "%d\n", result);

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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

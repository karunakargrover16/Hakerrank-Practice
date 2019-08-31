#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

typedef struct stack
{
  char data;
  struct stack* next;
}st;
char peek(st* top)
{
  return top->data;
}
void pop(st** top)
{
  *top= (*top)->next;
}
void push(st** top, char c)
{
  struct stack *tmp;
  tmp = (st*)malloc(sizeof(st));
  tmp -> data = c;
  tmp -> next= *top;
  (*top)=tmp;
}
int empty(st** top)
{
  if((*top)==NULL)
  {
    return 1;
  }
  return 0;
}

char** braces(int values_count, char** values, int* result_count) {
    char** result = (char**)malloc(values_count * sizeof(char*));
    int count = 0 ;
    char* yes="YES";
    char* no="NO";
    st* s;
    for(int i=0;i<values_count;i++)
    {
        s=NULL;
        char* str=*(values+i);
        for(int j=0;(*(str+j))!='\0';j++)
        {
            char c=*(str+j);
            if(empty(&s))
            {
               push(&s,c);
            }
            else
            {

              if((c=='{') || (c=='[') || (c=='('))
              {

                  push(&s, c);
              }
                else
                {

                    if((c=='}') && (peek(s)=='{'))
                    {
                        pop(&s);
                    }
                    else if((c==']') && (peek(s)=='['))
                    {
                        pop(&s);
                    }
                    else if((c==')') && (peek(s)=='('))
                    {
                        pop(&s);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if(empty(&s))
        {
            *(result+i)=yes;

        }
        else
        {
            *(result+i)=no;
        }
        count++;
    }
    *result_count=count;
    return result;


}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* values_count_endptr;
    char* values_count_str = readline();
    int values_count = strtol(values_count_str, &values_count_endptr, 10);

    if (values_count_endptr == values_count_str || *values_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** values = malloc(values_count * sizeof(char*));

    for (int i = 0; i < values_count; i++) {
        char* values_item = readline();

        *(values + i) = values_item;
    }

    int res_count;
    char** res = braces(values_count, values, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%s", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

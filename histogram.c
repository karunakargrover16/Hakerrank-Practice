#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));

    new->data = data;
    new->next = *top;
    *top = new;

}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void pop(st** top)
{

        st* temp=*top;
        *top=(*top)->next;
        free(temp);
        temp=NULL;
}

int getMaxArea(int* A, int n)
{
    int i=0,area=0,max=INT_MIN;
    st * top=NULL;
    for(i=0;i<n;i++)
    {
       if(empty(top))push(&top,i);
       else
       {
           if(A[peek(top)]<A[i])push(&top,i);
           else
           {
               while(!empty(top) && A[peek(top)]>A[i])
               {
                   int temp=peek(top);
                   pop(&top);
                   if(empty(top))
                   {
                       area=A[temp]*(i);
                   }
                   else
                   {
                       area=A[temp]*(i-1-peek(top));
                   }
                   max=max>area ? max : area;
               }
               push(&top,i);
           }
       }
    }
    while(!empty(top))
    {
       int temp=peek(top);
       pop(&top);
       if(empty(top))
        {
           area=A[temp]*(i);
        }
        else
        {
           area=A[temp]*(i-1-peek(top));
        }
        max=max>area ? max : area;
    }
    return max;

}


int main() {

    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);

    }

    int r = getMaxArea(arr, n);
    printf("%d", r);
    return 0;
}

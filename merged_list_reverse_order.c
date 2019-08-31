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
int peek(st* top)
{
  if(top==NULL)
    return -1;
  return top->data;
}
void pop(st** top)
{
   struct stack *tmp=(*top);
  *top= tmp->next;
}
void push(st** top, int c)
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
int main() {
    int i,j;
    st* s;
    int a1[3], a2[3], ans[6];
    for(i=0;i<3;i++)
        scanf("%d", &a1[i]);
    for(i=0;i<3;i++)
        scanf("%d", &a2[i]);
    i=0, j=0;
    while(i!=3 || j!=3)
    {
        if(((a1[i]<a2[j]) && (i!=3)) || j==3)
        {
            push(&s, a1[i]);
            i++;
        }
        else
        {
            push(&s, a2[j]);
            j++;
        }
    }
    for(i=0;i<6;i++)
    {
        ans[i]=peek(s);
        pop(&s);
    }
    for(i=0;i<6;i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}

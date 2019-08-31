#include <stdio.h>
#include<stdlib.h>
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

int main(void)
{
  int n,num;
  scanf("%d", &n);
  while(n){
	st* s=NULL;
	int i,j=0,x=1;
	int* arr=(int*)malloc(sizeof(int)*n);
	int* a=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
  {
    a[i]=0;
  }
	for(i=0;i<n;i++)
	{
		scanf("%d", (arr+i));
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			a[j]=x;
			x++;
			j++;
			continue;
		}
		else if(!empty(&s))
		{
      if(peek(s)==x)
			{
        pop(&s);
        a[j]=x;
			  j++;
			  x++;
      }
      push(&s, arr[i]);
		}
    else
		{
      push(&s, arr[i]);
    }
	}
	while(!empty(&s))
	{
		a[j]=peek(s);
		j++;
		pop(&s);
	}
  int flag=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]-a[i]==1)
			continue;
		printf("no\n");
    flag=1;
	}
  if(flag==0)
	{
    printf("yes\n");
  }
  scanf("%d", &num);
  n=num;
}
	return 0;
}

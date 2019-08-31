#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
	listnode* node = (listnode *) malloc(sizeof(listnode));
	node->val = val;
	node->next = NULL;
	return node;
}

void addNode(listnode* A, int i){
	listnode* temp = listnode_new(i);
	listnode* t = A;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}
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

int isPalin(listnode* A){
	 st* s;
	 struct ListNode* curr=A;
	 while(curr)
	 {
			 push(&s, curr->val);
			 curr=curr->next;
	 }
	 curr=A;
	 while(curr)
	 {
			 if(curr->val==peek(s))
			 {
					 pop(&s);
					 curr=curr->next;
					 continue;
			 }
			 else
			 return -1;
	 }
	 return 1;
}
int main(){
	int count = 0;
	int i;
	int v;
	scanf("%d",&count);
	scanf("%d",&v);
	listnode* A = listnode_new(v);
	for(i=0;i<count-1;i++){
		scanf("%d",&v);
		addNode(A,v);
	}
	if(isPalin(A) == 1) printf("true");
	else printf("false");
}

#include<stdio.h>
#include<stdlib.h>

/* structure for a node */
struct node
{
  int data;
  struct node *next;
};

vvoid sortedInsert(struct node** head, struct node* n)
{
    struct node* curr=*head;
    if(curr == NULL)
    {
        *head = n;
        n->next = *head;
    }
\    else
    {
        if(curr->data >= n->data)
        {
            n->next = curr;
            while(curr->next != *head)
                curr = curr->next;
            curr->next = n;
            *head = n;
        }
        else
        {
            while(curr->next->data < n->data && curr->next != *head)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;

        }
    }
}

void printList(struct node *start)
{
  struct node *temp;

  if(start != NULL)
  {
    temp = start;

    do {
      printf("%d\n", temp->data);
      temp = temp->next;
    } while(temp != start);
  }
}

/* Driver program to test above functions */
int main()
{
  int arr; //= {12, 56, 2, 11, 1, 90};
  int list_size, i;

  /* start with empty linked list */
  struct node *start = NULL;
  struct node *temp;

  int n;
  scanf("%d",&n);

  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for(i = 0; i< n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&arr);
    temp->data = arr;
    sortedInsert(&start, temp);
  }

  printList(start);
  //getchar();
  return 0;
}

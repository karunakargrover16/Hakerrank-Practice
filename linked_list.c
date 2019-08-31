#include<iostream>
using namespace std;
struct node
{
int info;
node *link;
};
int main()
{
int i,k,key1,key2,item;
struct node *start,*n,*ptr,*loc1,*loc2,*loc1p,*loc2p;
start = NULL;
cin>>k;
for(int i=0;i<k;i++)
{
    int data;
    cin>>data;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = data;
    n->link = start;
    start = n;
}
ptr = start;
while(ptr)
{
    cout<<ptr->info<<" ";
    ptr = ptr->link;
}
cout<<endl;
cin>>key1;
cin>>key2;
ptr=start;
loc1=NULL;
loc1p=loc1;
loc2=NULL;
loc2p=loc2;
while(ptr->link)
{
    if(ptr->link->info==key1)
    {
        loc1=ptr;
        loc1p=ptr->link;
    }
    if(ptr->link->info==key2)
    {
        loc2=ptr;
        loc2p=ptr->link;
    }
    ptr=ptr->link;
}
if(loc1==NULL)
{
    loc1=start;
    loc1p=loc1;


    ptr=loc2p->link;
    loc2->link=loc1p;
    loc2p->link=loc1p->link;
    loc1p->link=ptr;
    start=loc2p;

}
else if(loc2==NULL)
{
    loc2=start;
    loc2p=loc2;
    ptr=loc1p->link;
    loc1->link=loc2p;
    loc1p->link=loc2p->link;
    loc2p->link=ptr;
    start=loc1p;
}
else
{
    n=loc2p->link;
    loc1->link=loc2p;
    loc2p->link=loc1p->link;
    loc2->link=loc1p;
    loc1p->link=n;
}
ptr = start;
while(ptr)
{
    cout<<ptr->info<<" ";
    ptr = ptr->link;
}
return 0;
}

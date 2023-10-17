#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data; struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
int i;
struct Node *t,*last;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++)
{
t=(struct Node*)malloc(sizeof(struct Node));
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
}
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}


void insert(struct Node *p, int index,int x)
{

    struct Node *t;
    int i;
    i;
    if(index < 0 )
    {
        return;
    }

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {

        t->next=first;
        first=t;
    }

    else
    {
        for(i=0; i<index-1; i++)
        {
            p=p->next;
        }

        t->next=p->next;
        p->next=t;
    }
}


int main()

{
    int A[]={10,20,30,40,60};
     create(A,5);
     insert(first,0,5);
     insert(first,5,50);
     display(first);
     return 0;
}

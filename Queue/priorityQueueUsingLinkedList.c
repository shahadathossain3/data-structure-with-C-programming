#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
}*front=NULL;


void enqueue(int x, int priority)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(int));
    if(t==NULL)
    {
        printf("Queue is full");
    }
    else if(front==NULL)
    {
        t->data=x;
        t->next=NULL;
        front=t;
    }
    else
    {
        struct Node *p,*q;
        p=front;

        while(p && p->priority < x)
        {
            q=p;
            p=p->next;
        }

        if(x<front->data)
        {
           t->data=x;
           t->next=front;
           front=t;
        }

        else
        {
            t->data=x;
            q->next=t;
            t->next=p;
        }
    }

}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int dequeue()
{
    int x=-1;
    struct Node *t;
    if(front==NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}


int main()
{
    enqueue(10,3);
    enqueue(20,4);
    enqueue(40,1);
    enqueue(122,2);
    enqueue(93,8);
    enqueue(15,3);
    Display(front);
    dequeue();
     Display(front);
    return 0;
}

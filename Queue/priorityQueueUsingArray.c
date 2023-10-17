#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *priorites;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(size*sizeof(int));
    q->priorites=(int *)malloc(size*sizeof(int));
}

void enqueue(struct Queue *q, int data, int priority)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is full\n");
    }

    else
    {
        int i=q->rear;
        while((i>=0) && (q->priorites[i]>priority))
        {
            q->Q[i+1]=q->Q[i];
            q->priorites[i+1]=q->priorites[i];
            i--;
        }
        q->Q[i+1]=data;
        q->priorites[i+1]=priority;
        q->rear++;

    }

}


int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("Queue is Empty");
    }

    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}


void Display(struct Queue q)
{
    int i;
    for(i=q.front+1; i<=q.rear; i++)
    {
        printf("(%d , %d) \n",q.Q[i],q.priorites[i]);
    }
    printf("\n");
}



int main()
{
    struct Queue q;
    create(&q,5);

    enqueue(&q,10,3);
    enqueue(&q,30,4);
    enqueue(&q,40,1);
    enqueue(&q,50,2);
    enqueue(&q,60,3);


    Display(q);
    printf("%d \n",dequeue(&q));
    Display(q);
    return 0;

}


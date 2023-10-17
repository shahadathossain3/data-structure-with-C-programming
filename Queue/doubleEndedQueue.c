#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}


void input_rear(struct Queue *q, int x)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}


int output_rear(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->rear--;
        x=q->Q[q->rear];
    }

    return x;
}


void input_front(struct Queue *q, int x)
{
    if(q->front==-1)
    {
        printf("cannot insert front");
    }
    else
    {
        q->front--;
        q->Q[q->front]=x;
    }
}


int output_front(struct Queue *q)
{
    int x=-1;

    if(q->front==q->rear)
    {
        printf("Queue is Empty\n");
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
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    int n;

    create(&q,5);

    input_rear(&q,10);
    input_rear(&q,30);
    input_rear(&q,40);
    input_rear(&q,50);
    input_rear(&q,60);

    printf("Enter 1 for input raer input\n Enter 2 for rear output\n Enter 3 for front input\n Enter 4 for front output\n");


    while(scanf("%d",&n)!=EOF)
    {

      if(n==3){
          int m;
          printf("Enter element");
          scanf("%d",&m);
         input_front(&q,m);
         Display(q);

      }
       if(n==4){
         output_front(&q);
         Display(q);
       }
       if(n==1){
          int m;
           printf("Enter element");
          scanf("%d",&m);
         input_rear(&q,m);
         Display(q);
       }
       if(n==2){
         output_rear(&q);
         Display(q);
       }


    }

}

#include <stdio.h>
#include<stdlib.h>


struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

struct stack
{
    int size;
    int top;
    struct Node **S;
};


void queueCreate(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
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


struct Node *dequeue(struct Queue *q)
{
    struct Node* x=NULL;
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
};

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}


void treeCreate(int nodeNumber)
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    queueCreate(&q, nodeNumber);

    printf("Enter root value ");
    scanf("%d",&x);
    root=(struct Node*)malloc(sizeof(struct Node ));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}







int count(struct Node *root)
{
if(root)
{
return count(root->lchild)+count(root->rchild)+1;
}
return 0;
}


int height(struct Node *root)
{
int x=0,y=0;
if(root==0)
{
return 0;
}
x=height(root->lchild);
y=height(root->rchild);

return (x > y ? x : y) + 1;
}


int main()
{
  int n;
    printf("Enter the node number ");
    scanf("%d",&n);
    treeCreate(2*n);
printf("Count %d",count(root));
printf("\n");
printf("Height %d",height(root));
return 0;
}

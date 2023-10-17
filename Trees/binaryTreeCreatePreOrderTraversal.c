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
    root=(struct Node*)malloc(sizeof(struct Node));
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

void preOrder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}


void InOrder(struct Node *p)
{
    if(p)
    {
        preOrder(p->lchild);
        printf("%d ",p->data);
        preOrder(p->rchild);
    }
}


void postOrder(struct Node *p)
{
    if(p)
    {
        preOrder(p->lchild);
        preOrder(p->rchild);
        printf("%d ",p->data);
    }
}

int main()
{
    int n;
    printf("Enter the node number ");
    scanf("%d",&n);
    treeCreate(2*n);
    printf("Preorder ");
    preOrder(root);
    printf("\n");
    printf("Inorder ");
    InOrder(root);
    printf("\n");
    printf("postOrder ");
    postOrder(root);
    return 0;
}

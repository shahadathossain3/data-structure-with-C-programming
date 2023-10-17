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


void createStack(struct stack *st, int size)
{

    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node*));
}

void push(struct stack *st, struct Node *x)
{
    if(st->top==st->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int isEmptyStack(struct stack st)
{
    if(st.top==-1)
    {
        return 1;
    }
    return 0;
}



struct Node *pop(struct stack *st)
{
    struct Node *x;
    if(st->top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x=st->S[st->top--];
    }
    return x;
};


struct Node *stackTop(struct stack *st)
{
    struct Node *x;
    if(st->top==-1)
    {
       // return st->S[st->top];
       printf("Stack Undeflow\n");
    }
    else
    {
        x=st->S[st->top];
        return x;
    }
};

void preOrder(struct Node *p)
{
    struct stack stk;
    createStack(&stk,100);
    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void InOrder(struct Node *p)
{
    struct stack st;
    createStack(&st,100);
    while(p || !isEmptyStack(st))
    {
        if(p)
        {
            push(&st,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&st);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}


void postOrder(struct Node *p)
{
    struct stack st;
    createStack(&st, 100);
    struct Node *prev = NULL;

    while (p || !isEmptyStack(st))
    {
        if (p)
        {
            push(&st, p);
            p = p->lchild;
        }
        else
        {
            struct Node *temp = stackTop(&st);

            if (temp->rchild != NULL && temp->rchild != prev)
            {
                p = temp->rchild;
            }
            else
            {
                p = pop(&st);
                printf("%d ", p->data);
                prev = p;
                p = NULL;
            }
        }
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
    printf("InOrder ");
    InOrder(root);
    printf("\n");
    printf("PostOrder ");
    postOrder(root);
}

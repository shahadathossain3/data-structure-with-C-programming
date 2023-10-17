#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;


struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }
    else if(key>p->rchild,key)
    {
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}


struct Node* search(int key)
{
    struct Node* t = root;
    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
    {
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node *InOrderPredecossor(struct Node *p)
{
    while(p&& p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct Node *InOrderSuccess(struct Node *p)
{
    while(p && p->lchild!=NULL)
    {
        p->lchild;
    }
    return p;
}


struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        free(p);
        return NULL;
    }

    if(key<p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InOrderPredecossor(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InOrderSuccess(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}


int main()
{
struct Node *temp;
root=RInsert(root,50);
RInsert(root,10);
RInsert(root,40);
RInsert(root,20);
RInsert(root,30);
inorder(root);
printf("\n");
printf("\n");
temp=search(20);
if(temp!=NULL)
printf("element %d is found\n",temp->data);
else
printf("element is not found\n");

Delete(root,30);
printf("\nAfter Delete ");
inorder(root);
printf("\n");
return 0;
}


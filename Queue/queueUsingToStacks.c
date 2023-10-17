#include<stdio.h>
#include<stdlib.h>


struct stack
{
    int size;
    int top;
    int *S;
};

void create(struct stack *s, int size)
{
    s->size=size;
    s->top=-1;
    s->S=(int *)malloc(s->size*sizeof(int));
}

void push(struct stack *st, int x)
{
   if(st->top==st->size-1)
   {
       printf("Stack is overflow\n");
   }
   else
   {
       st->top++;
       st->S[st->top]=x;
   }
}


int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        x=st->S[st->top--];
    }
    return x;
}


void Display(struct stack *st)
{
    int i=st->top;

    while(i>=0)
    {
        printf("%d ",st->S[i]);
        i--;
    }

    printf("\n");
}




int main()
{
    struct stack s1,s2;

    create(&s1,5);
    create(&s2,5);

    push(&s1,10);
    push(&s1,20);
    push(&s1,30);
    push(&s1,40);
    push(&s1,50);

    Display(&s1);

    for(int i=0; i<s1.size; i++)
    {
        push(&s2,pop(&s1));
    }

    Display(&s2);

    pop(&s2);

    Display(&s2);
    return 0;
}

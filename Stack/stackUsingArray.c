#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *S;
};

void create(struct stack *st)
{
    printf("Enter Size = 4\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void push(struct stack *st, int x)
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

void Display(struct stack st)
{
    int i;
    for(i=st.top; i>=0; i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack Underflow\n");
    }

    else
    {
        x=st->S[st->top--];
       // x=st->S[st->top];
        //st->top--;
    }
    return x;
}

int peek(struct stack st, int index)
{
    int x=-1;
    if(st.top-index+1<0)
    {
        printf("Invalid Index");
    }

    x=st.S[st.top-index+1];
    return x;
}

int isEmpty(struct stack st)
{
    if(st.top==-1)
    {
        return 1;
    }

    return 0;
}

int isFull(struct stack st)
{


    return st.top==st.size-1?1:0;

}


int stackTop(struct stack st)
{
 return isEmpty!=NULL? st.S[st.top]:-1;
}



int main()
{
    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);



    Display(st);
    printf("pop = %d\n", pop(&st));
    Display(st);
    printf("peek = %d\n",peek(st,2));
    printf("stackTop = %d\n",stackTop(st));
    printf("isEmpty = %d\n",isEmpty(st));
    printf("isFull = %d\n",isFull(st));

}

#include<stdio.h>


int sum=0;
void fun(int n)
{
    if(n>0)
    {
        printf(" %d ",n);

        fun(n-1);
        sum+=n;
        printf(" %d ",sum);
        fun(n-1);
    }
}

int main()
{
    fun(3);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int i;
    p=(int *)malloc(5*sizeof(int));
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;

    for(i=0; i<5; i++)
    {
        printf("%d ",p[i]);
    }
    return 0;
}

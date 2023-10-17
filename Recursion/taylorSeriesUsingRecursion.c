#include<stdio.h>

double e(int x, int n)
{
    static double p=1,f=1;
    if (n==0)
    {
        return 1;
    }

    else
    {
       double r = e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}

int main()
{
    printf("%lf",e(4,15));
}

#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0; i<arr.length-1; i++)
    {
    if(arr.A[i]>arr.A[i+1])
    {
        return 0;
    }
    }
    return 1;
}

int main()
{
   struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
int sort=isSorted(arr1);
if(sort==1)
{
    printf("Sort");
}
else
{
    printf("No Sort");
}
return 0;
}

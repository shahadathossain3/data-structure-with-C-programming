#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int linearSearch(struct Array *arr, int key)
{
    int i;
    for(i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}


int main()
{

    struct Array arr1={{2,23,14,5,6,9,8,12},10,8};
    printf("%d\n",linearSearch(&arr1,23));
    Display(arr1);
    return 0;
}

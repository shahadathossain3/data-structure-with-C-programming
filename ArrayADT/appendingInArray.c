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

void append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length++]=x;
    }
}


int main()
{

    struct Array arr1={{2,3,4,5,6},10,5};
    printf("Before Insert\n");
    Display(arr1);
    printf("\n\n");
    printf("After Insert\n");
    append(&arr1,10);
    Display(arr1);
    return 0;
}

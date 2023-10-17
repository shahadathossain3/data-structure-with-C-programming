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

void insert(struct Array *arr, int index, int x)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length; i>index; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int main()
{

    struct Array arr1={{2,3,4,5,6},10,5};
    printf("Before Insert\n");
    Display(arr1);
    printf("\n\n");
    printf("After Insert\n");
    insert(&arr1,3,10);
    Display(arr1);
    return 0;
}

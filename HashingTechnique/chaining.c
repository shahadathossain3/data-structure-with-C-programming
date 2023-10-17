#include<stdio.h>
#include "chains.h"

int hash(int key)
{
    return key%10;
}

void insert(struct Node *H[], int key)
{
    int index=hash(key);
    sortedInsert(&H[index],key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;
    for(i=0; i<10; i++)
    {
        HT[i]=NULL;
    }
    insert(HT,12);
    insert(HT,22);
    insert(HT,42);
    temp=Search(HT[hash(22)],22);
    if(temp)
    {
    printf("%d ", temp->data);
    }
    else
    {
        printf("Not Found");
    }
    return 0;
}

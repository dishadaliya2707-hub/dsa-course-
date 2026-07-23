#include <stdio.h>
int main()
{
    int arr1[5]={95,98,90,89,75};
    int arr2[5]={99,85,79,86,92};
    int arr3[10];
    for (int i=0;i<5;i++)
    {
        arr3[i]=arr1[i];
    }
    for (int i=0;i<5;i++)
    {
        arr3[i+5]=arr2[i];
    }    
    printf("arr1: ");
    for (int i=0;i<5;i++)
    {
        printf("%d \n",arr1[i]);
    }
    printf("arr2: ");
    for (int i=0;i<5;i++)
    {
        printf("%d \n",arr2[i]);
    }
    printf("arr3: ");
    for (int i=0;i<10;i++)
    {
        printf("%d \n",arr3[i]);
    }
    return 0;
}


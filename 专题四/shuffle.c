#include <stdio.h>
#include <stdlib.h>

void Quicksort(int a[],int left,int right)
{
    if(left >= right)
    {
        return;
    }
    int i=left,j=right,key=a[left];
    while(i<j)
    {
        while(i<j && key<=a[j])
        {
            j--;
        }
        a[i]=a[j];
        while(i<j && key>=a[i])
        {
            i++;
        }
        a[j]=a[i];
    }
    a[i]=key;
    Quicksort(a,left,i-1);
    Quicksort(a,i+1,right);
}

int main()
{
    int a[52];
    int i;
    for(i=0;i<52;i++)
        a[i]=i+1;
    Quicksort(a,0,51);
    for(i=0;i<52;i++)
        printf("%d  ",a[i]);
    return 0;
}

#include <stdio.h>

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
    int a[]={3,5,4,2,6,9,8,8,7,8,15};
    int i,n=11;
    Quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

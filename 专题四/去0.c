#include<stdio.h>


int RemoveZeroElements(int *a[],int n)
{
    int i,j,m;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            for(j=i;j<n-1;j++)
            {
                a[j]=a[j+1];
            }
            i--;
            n--;
        }
    }
    m=n;
    return m;
}


int main()
{
    int a[]={1,2,3,4,5,0,6,4,5,0,5,0,0,0,5};
    int n=14;
    int i,j;
    j=RemoveZeroElements(a,n);
    for(i=0;i<j;i++)
        printf("%d\n",a[i]);
    printf("Number:%d",j);
    return 0;
}

#include<stdio.h>


int RemoveDuplicates(int a[],int n)
{
    int i,j,k,m;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]==a[i])
            {
                for(k=i;k<n-1;k++)
                    a[k]=a[k+1];
                i--;
                n--;
                break;
            }
        }

    }

    m=n;
    return m;
}


int main()
{
    int a[]={9,8,7,7,4,3,4,5};
    int n=8;
    int i,j;
    j=RemoveDuplicates(a,n);
    for(i=0;i<j;i++)
        printf("%d,",a[i]);
    printf("Number:%d",j);
    return 0;
}

#include<stdio.h>
void Mele(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];a[j]=a[j+1];a[j+1]=temp;
            }
        }
    }
}

void Gele(int a[],int n)
{
    if(n>1)
     {  int i,i1=0,i2=0;
        int n1=n/2;
        int n2=n-n2;
        int a1[n1],a2[n2];
        for(i=0;i<n/2;i++)
            a1[i]=a[i];
        for(i=n/2;i<n;i++)
            a2[i-n/2]=a[i];
        Mele(a1,n1);
        Mele(a2,n2);
        i=0;
        while(i1<n1&&i2<n2)
        {
            if(a1[i1]<a2[i2])
                a[i++]=a1[i1++];
            else
                a[i++]=a2[i2++];
        }
        while (i1 < n1) a[i++] = a1[i1++];
        while (i2 < n2) a[i++] = a2[i2++];
    }
}

int main()
{
    int a[]={1,2,5,6,8,2,5,4,3,9};
    int n=10,i;
    Mele(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

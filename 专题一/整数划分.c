#include<stdio.h>
int a[100]={0};
void fen(int n,int pos)             //pos�����е�λ��
{
    int i;
    if(n==0)                       //����,���
    {
        int ji;
        for(ji=0;ji<pos;ji++)
            printf("%d ",a[ji]);
        printf("\n");
    }
    else                          //δ���,��
        for(i=n;i>0;i--)
        {
            if(pos==0||i<=a[pos-1])
            {
                a[pos]=i;            //д��
                fen(n-i,pos+1);
            }
        }
}


int main()
{
    int n;
    printf("Please enter an int\n");
    scanf("%d",&n);
    fen(n,0);
}





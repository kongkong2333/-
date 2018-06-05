#include<stdio.h>
int i=1;
void move(int n,char from,char to)
{
   printf("第%d步:将%d号盘子%c---->%c\n",i++,n,from,to);//将n个盘从from移到to
}

void Hanoi(int n,char start_pos,char tran_pos,char end_pos)
{
    if(n==1){
        move(n,start_pos,end_pos);
    }
    else{
        Hanoi(n-1,start_pos,end_pos,tran_pos);
        move(n,start_pos,end_pos);
        Hanoi(n-1,tran_pos,start_pos,end_pos);
    }
}


int main()
{
    int n;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    printf("Input the number of disks:");
    scanf("%d",&n);
    Hanoi(n,A,B,C);
    printf("最后的总步数为%d\n",i-1);
    return 0;
}

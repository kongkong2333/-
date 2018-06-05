#include<stdio.h>
#include<stdlib.h>
typedef struct node     /*这个结构类型包括三个域 */
{	int number;        /*猴子的编号*/
	int mydata;        /* 猴子的定数 */
	struct node *next; /* 指向下一只猴子的指针 */
} linklist;
linklist *CreateCircle( int n ){ /* 创建单循环链表，返回最后一个结点的指针   */
    linklist *head,*p,*s;
    int i;
    head =(linklist*)malloc(sizeof(linklist)); /*首节点创建*/
    p = head;   p->number = 1;
    printf("please input a number:");
    scanf("%d",&p->mydata); /* 定数(正整数)，确定下一只出局的猴子*/
    p->next = NULL;
    for( i=2; i<=n; i++ ){  /* 链表创建*/
		s = (linklist*)malloc(sizeof(linklist) ); /*  创建新节点 */
		s->number = i; /*  给新猴子编号 */
		printf("please input a number:");
		scanf("%d",&s->mydata); /* 报数(正整数)，确定下一只出局的猴子*/
		p->next = s; /*  连接新节点 */
		p = s;  /*  p指向新节点 */
    }
    p->next=head;   /*链表首尾相接构成循环链表*/
    return p;  /* 返回最后一只猴子的指针，因为它指向第一只猴子 */
}
linklist *DeleteNext(linklist *p)    /* 删除单循环链表的p所指的下一个结点 */
{  linklist   *s;
         if ( p && p->next!=p) {
               s = p->next;                /*s指向p所指的下一个结点  */
               p->next = s->next;     /*从链表中删除*/
               free(s);                         /*释放被删除结点 */
               return p;
         }else if(p){                 /* 若单循环链表只有一个结点 */
               free(p);
               return NULL;
         }else
               return NULL;

}


int KingOfMonkey(int n,linklist *head){
    linklist *p = head;       /* head指向最后一只猴子结点 */
    int i, j, steps = p->mydata;       /*用最后一只猴子的定数开始 */
    for( j=1; j<=n-1; j++ ) {   /*重复该过程n-1次*/
        for( i=1; i<steps; i++ )    p=p->next;
	    /* 将p所指的下一个节点删除, 删除前取其定数 */
        steps = p->next->mydata;  /*  取定数 */
        printf(" %d ", p->next->number);
        DeleteNext(p);    /*  调用函数删除p所指的下一个结点 */
    }
    return p->number;     /*  返回王的编号 */
 }
int main(){
    linklist *head;
    int n;
    printf("请输入猴子的总数和每只猴子的定数(必须是正整数)：");
    scanf("%d",&n);
    head = CreateCircle(n); /*创建单循环链表，返回最后一个结点的指针 */
    printf("\nThe king is monkey[%d].\n", KingOfMonkey(n,head));
    return 0;
}

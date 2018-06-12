#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MAX 30


typedef struct                            //存放多项式的数组类
{
    double coe;                           //系数
    int index;                            //指数
}PolyArray;

typedef struct PolyNode                   //定义单链表结点类型，保存多项式中的一项，链表构成多项式
{
    double coe;
    int index;
    struct PolyNode *next;
}PolyLinkList;


void Display(PolyLinkList *head)             //输出多项式
{
    bool first=true;                      //first==true时为第一项
    PolyLinkList *p=head->next;
    while(p!=NULL)
    {
        if(first)
            first=false;
        else if(p->coe > 0)
            printf("+");
        if(p->index==0)
            printf("%g",p->coe);
        else if(p->index==1)
            printf("%gx",p->coe);
        else
            printf("%gx^%d",p->coe,p->index);
        p=p->next;
    }
    printf("\n");
}


void Free(PolyLinkList *head)            //释放单链表
{
    PolyLinkList *p=head,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

void CreateList(PolyLinkList **head,PolyArray a[],int n)    //尾插法建表
{
    PolyLinkList *new_,*ternode;                                //ternode 始终指向终端节点
    int i;
    (*head)=(PolyLinkList *)malloc(sizeof(PolyLinkList));      //创建头节点
    (*head)->next=NULL;
    ternode=(*head);
    for(i=0;i<n;i++)
    {
        new_=(PolyLinkList *)malloc(sizeof(PolyLinkList));  //创建新节点
        new_->coe=a[i].coe;
        new_->index=a[i].index;
        ternode->next=new_;                                 //ternode插入new之后
        ternode=new_;
    }
    ternode->next=NULL;                                           //终端节点指向NULL
}

void Sort(PolyLinkList *head)                               //按index递减排序
{
    PolyLinkList *p=head->next,*q,*r;
    if(p!=NULL)                                             //如果原单链表有数据节点
    {
        r=p->next;                                          //r保存p结点后一个结点的指针
        p->next=NULL;                                       //只有一个数据节点
        p=r;
        while(p!=NULL)
        {
            r=p->next;                                     //r保存p结点后一个结点的指针
            q=head;
            while(q->next!=NULL && q->next->index > p->index)
                q=q->next;                                 //在有序表中找插入*p的前驱结点*q
            p->next=q->next;                               //将*p插入到*q之后
            q->next=p;
            p=r;
        }
    }
}


int InverseList(PolyLinkList *head) //逆置链表
{
    PolyLinkList*p=head->next,*q; //p指向正要逆置的节点，q指向下一个待逆置的节点
    head->next=NULL;
    while(p)    //当前节点不为空
    {
        q=p->next;//保存下一个节点
        p->next=head->next; //先更新逆置点的 next
        head->next=p;        //在更新head->next
        p=q;           //下一轮
    }
    return 0;
}
PolyLinkList *MultiplisePoly(PolyLinkList *head_a,PolyLinkList *head_b)//链式相乘
{
    PolyLinkList *head_c,*pa=head_a,*pb=head_b,*pc,*newnode;
    int index_max; //指数之和最大值
    if(pa->next!=NULL && pb->next!=NULL)
         index_max=pa->next->index+pb->next->index; //获取最大指数和
    else return NULL;
    //初始化链表C头结点
    head_c=(PolyLinkList *)malloc(sizeof(PolyLinkList));
    if(NULL==head_c)
    {   printf("开辟链表C失败\n");
        exit(-1);
    }
    head_c->coe=0.0;
    head_c->index=0;
    head_c->next=NULL;
    pc=head_c;
    InverseList(head_b);    //逆置b链表
    float ceof=0.0;
    for(int k=index_max;k>=0;k--)
    {
        pa=head_a->next; //恢复pa的指向
        while(pa!=NULL && pa->index>k) //首先查找pa的位置 找不大于k的
                pa=pa->next;
        pb=head_b->next;//恢复Pb的指向
        while(pa!=NULL && pb!=NULL && pa->index+pb->index<k)//然后在查找pb的位置 pa+pb的指数和不大于k
                pb=pb->next;
        //经过上面两轮后 pa+pb 的index<=k
        while(pa!=NULL && pb!=NULL)//此循环进入后,找到所有的同指数的和相加
        {
            if(k==pa->index+pb->index)  //目的就是找等于K
            {
                ceof+=pa->coe*pb->coe;
                pa=pa->next;
                pb=pb->next;
            }
            else
            {
                if(pa->index+pb->index<k) //小于k 增加pb
                    pb=pb->next;
                else
                    pa=pa->next; //大于k 减小pa
            }

        }
        if(ceof!=0.0)   //有系数了 就将此节点插入到c链表中
        {
            if(NULL==(newnode=(PolyLinkList *)malloc(sizeof(PolyLinkList))))
            {
                printf("链表C节点开辟失败");
                exit(-1);
            }
            newnode->coe=ceof;
            newnode->index=k;
            newnode->next=NULL; //插入节点数据

            pc->next=newnode;
            pc=newnode;         //插入节点
            ceof=0.0;
        }
    }

        InverseList(head_b);
        return head_c;
}

/* 链式相乘：
思路：
1.因为两个链表都是指数递减，所以A(X)递减，B(x)逆置下，递增,why do this?
2.先获取两个最大的指数和 exp_max. 这样的话余下的指数就是都在0~7之间了。
    关键来了，遍历相乘本质并不难，但是如何可以找到所有的指数呢？而且还要开辟新的节点来存储没有的指数
解决：用一个新的链来存储结果，从exp_max开始向下查找,每一个可能指数都要遍历到。
这里指数升序+降序的排列就很精妙了。
    for(k=exp_max;k>=0;k--)
    {
        相乘;
        判断是否还有同类的系数，有就相加;
    }
如何判断呢？就是在步进查找。
若是当前k值,表明该指数找到了，此时就是a,b都后继一位，因为只有这种组合才可能有同样系数
若是当前指数<k,表明则表明要增加系数和，只有a增加
若是当前指数>k,表明要减少系数和，只有b增加
 这也就看出了，a,b两个链表指数一个升序一个降序的好处了。这种思路很好

3.归纳总结下：
 3.1 求k=exp_max;
 3.2 逆置b
 3.3 遍历查找 怎么做循环又是个问题
  一旦查找到了 =k的情况,然后就继续搜索其他可能性 直到都到NULL节点
                                                                    */
int main()
{
    PolyLinkList *fir,*sec,*thi;
    PolyArray a[]={{1.5,0},{2.6,2},{3.6,1},{5.6,4}};
    PolyArray b[]={{-1.2,0},{2.5,1},{3.2,3},{2.5,5},{5.4,10}};
    CreateList(&fir,a,4);
    CreateList(&sec,b,5);
    printf("First:  ");
    Display(fir);
    printf("Second: ");
    Display(sec);
    Sort(fir);
    Sort(sec);                                         //降幂排序
    thi=MultiplisePoly(fir,sec);
    InverseList(thi);
    printf("Multiplication:    ");
    Display(thi);
    return 0;
}

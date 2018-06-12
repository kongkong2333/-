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


void Add(PolyLinkList *fir,PolyLinkList *sec,PolyLinkList **thi)  //加法
{
    PolyLinkList *fir_=fir->next,*sec_=sec->next,*s,*tc;
    double c;
    (*thi)=(PolyLinkList *)malloc(sizeof(PolyLinkList));          //创建头节点
    tc=(*thi);
    while (fir_!=NULL && sec_!=NULL)
    {
        if(fir_->index > sec_->index)
        {
            s=(PolyLinkList *)malloc(sizeof(PolyLinkList));   //复制节点
            s->index = fir_->index;
            s->coe=fir_->coe;
            tc->next=s;
            tc=s;
            fir_=fir_->next;
        }
        else if(fir_->index < sec_->index)
        {
            s=(PolyLinkList *)malloc(sizeof(PolyLinkList));    //复制节点
            s->index=sec_->index;
            s->coe=sec_->coe;
            tc->next=s;
            tc=s;
            sec_=sec_->next;
        }
        else                                                   //fir->index==sec==index
        {
            c=fir_->coe +sec_->coe;
            if(c!=0)
            {
                s=(PolyLinkList *)malloc(sizeof(PolyLinkList));//复制节点
                s->index=fir_->index;
                s->coe=c;
                tc->next=s;
                tc=s;
            }
            fir_=fir_->next;
            sec_=sec_->next;
        }
    }
    if(sec_!=NULL)
        fir_=sec_;                                              //复制余下节点
    while (fir_ != NULL)
    {
        s=(PolyLinkList *)malloc(sizeof(PolyLinkList));       //复制节点
        s->index=fir_->index;
        s->coe=fir_->coe;
        tc->next=s;
        tc=s;
        fir_=fir_->next;
    }
    tc->next=NULL;
}



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
    Sort(sec);
    Add(fir,sec,&thi);
    printf("Sum:    ");
    Display(thi);
    return 0;
}

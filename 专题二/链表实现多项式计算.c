#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MAX 30


typedef struct                            //��Ŷ���ʽ��������
{
    double coe;                           //ϵ��
    int index;                            //ָ��
}PolyArray;

typedef struct PolyNode                   //���嵥���������ͣ��������ʽ�е�һ������ɶ���ʽ
{
    double coe;
    int index;
    struct PolyNode *next;
}PolyLinkList;


void Display(PolyLinkList *head)             //�������ʽ
{
    bool first=true;                      //first==trueʱΪ��һ��
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


void Free(PolyLinkList *head)            //�ͷŵ�����
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

void CreateList(PolyLinkList **head,PolyArray a[],int n)    //β�巨����
{
    PolyLinkList *new_,*ternode;                                //ternode ʼ��ָ���ն˽ڵ�
    int i;
    (*head)=(PolyLinkList *)malloc(sizeof(PolyLinkList));      //����ͷ�ڵ�
    (*head)->next=NULL;
    ternode=(*head);
    for(i=0;i<n;i++)
    {
        new_=(PolyLinkList *)malloc(sizeof(PolyLinkList));  //�����½ڵ�
        new_->coe=a[i].coe;
        new_->index=a[i].index;
        ternode->next=new_;                                 //ternode����new֮��
        ternode=new_;
    }
    ternode->next=NULL;                                           //�ն˽ڵ�ָ��NULL
}

void Sort(PolyLinkList *head)                               //��index�ݼ�����
{
    PolyLinkList *p=head->next,*q,*r;
    if(p!=NULL)                                             //���ԭ�����������ݽڵ�
    {
        r=p->next;                                          //r����p����һ������ָ��
        p->next=NULL;                                       //ֻ��һ�����ݽڵ�
        p=r;
        while(p!=NULL)
        {
            r=p->next;                                     //r����p����һ������ָ��
            q=head;
            while(q->next!=NULL && q->next->index > p->index)
                q=q->next;                                 //����������Ҳ���*p��ǰ�����*q
            p->next=q->next;                               //��*p���뵽*q֮��
            q->next=p;
            p=r;
        }
    }
}


void Add(PolyLinkList *fir,PolyLinkList *sec,PolyLinkList **thi)  //�ӷ�
{
    PolyLinkList *fir_=fir->next,*sec_=sec->next,*s,*tc;
    double c;
    (*thi)=(PolyLinkList *)malloc(sizeof(PolyLinkList));          //����ͷ�ڵ�
    tc=(*thi);
    while (fir_!=NULL && sec_!=NULL)
    {
        if(fir_->index > sec_->index)
        {
            s=(PolyLinkList *)malloc(sizeof(PolyLinkList));   //���ƽڵ�
            s->index = fir_->index;
            s->coe=fir_->coe;
            tc->next=s;
            tc=s;
            fir_=fir_->next;
        }
        else if(fir_->index < sec_->index)
        {
            s=(PolyLinkList *)malloc(sizeof(PolyLinkList));    //���ƽڵ�
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
                s=(PolyLinkList *)malloc(sizeof(PolyLinkList));//���ƽڵ�
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
        fir_=sec_;                                              //�������½ڵ�
    while (fir_ != NULL)
    {
        s=(PolyLinkList *)malloc(sizeof(PolyLinkList));       //���ƽڵ�
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

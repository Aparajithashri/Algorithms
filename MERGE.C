#include<stdio.h>
#include<conio.h>

struct node
{
int data;
struct node *next;
};

void push(struct node **h,int d)
{
struct node *p=(struct node *)malloc(sizeof(struct node));
p->data=d;
p->next=(*h);
(*h)=p;
}
void split(struct node *source,struct node **a,struct node **b)
{
struct node *fast,*slow;
fast=source->next;
slow=source;
while(fast!=NULL)
{
fast=fast->next;
if(fast!=NULL)
{
slow=slow->next;
fast=fast->next;
}
}
(*a)=source;
(*b)=slow->next;
slow->next=NULL;
}
struct node *merge(struct node *a,struct node *b)
{
struct node *result=NULL;
if(a==NULL)
return b;
else if(b==NULL)
return a;
if(a->data<=b->data)
{
result=a;
result->next=merge(a->next,b);
}
else
{
 result=b;
result->next=merge(a,b->next);
}
return result;
}

void mergesort(struct node **h)
{
struct node *a=NULL;
struct node *b=NULL;
struct node *head=(*h);
if(head==NULL || head->next==NULL)
return;

split(head,&a,&b);
mergesort(&a);
mergesort(&b);
(*h)=merge(a,b);
}
void print(struct node *st)
{
while(st!=NULL)
{
printf("%d ",st->data);
st=st->next;
}
}
int main()
{
struct node *start=NULL;
clrscr();
push(&start,20);
push(&start,2);
push(&start,8);
push(&start,98);
push(&start,5);
mergesort(&start);
print(start);
getch();
return 0;
}
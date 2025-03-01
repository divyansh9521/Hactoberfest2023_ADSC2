#include<stdio.h>
#define MAXQUE 5
typedef struct 
{
	int rear;
	int front;
	int item[MAXQUE];
}Queue;
int IsEmpty(Queue*);
int IsFull(Queue *);
void Insert(Queue *,int);
int Delete(Queue *);
int Peep(Queue *);
void Display(Queue *);
int main()
{
	Queue q;
	int x,ch,ele;
	q.front = 0;
	q.rear = -1;
	do
	{
		printf("\n1-Insert");
		printf("\n2-Delete");
		printf("\n3-Peep");
		printf("\n4-Display");
		printf("\n5-OUIT");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
		case 1: printf("\nEnter the elements to insert : ");
					scanf("%d",&ele);
					Insert(&q,ele);
					break;
			case 2: ele = Delete(&q);
					if(ele==-1)
						printf("\nQueue is empty!");
					else
						printf("\nThe Deleted element is %d",ele);
					break;
			case 3: ele = Peep(&q);
					if(ele == -1)
						printf("\nThe Queue is empty");
					else
						printf("\nThe Peeped element is = %d",ele);
					break;
			case 4: Display(&q);
					break;
			case 5: break;
			default: printf("\nWrong choice : Try again");
		}
	}while(ch!=5);
	return 0;
}
int IsEmpty(Queue* q)
{
	if(q->rear<q->front)
		return 1;
	else
		return 0;
}
int IsFull(Queue* q)
{
	if(q->rear==MAXQUE-1)
		return 1;
	else
		return 0;
}
void Insert(Queue* q,int x)
{
	if(IsFull(q))
	{
		printf("\nQueue is full");
		return;
	}
	else
	{
		q->rear++;
		q->item[q->rear]=x;
	}
}
int Delete(Queue* q)
{
	int x;
	if(IsEmpty(q))
	{
		return -1;
	}
	else
	{
		x=q->item[q->front];
		q->front++;
		return x;
	}
}
int Peep(Queue* q)
{
	int x;
	if(IsEmpty(q))
	{
		return -1;
	}
	else
	{
		x=q->item[q->front];
		return x;
	}
}
void Display(Queue* q)
{
	int i;
	if(IsEmpty(q))
	{
	    printf("\nQueue is Empty");
	    return;
	}
	for(i=q->front;i<=q->rear;i++)
	    printf("%d\t",q->item[i]);
}

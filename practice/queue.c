#include<stdio.h>

int queue[100];
int size=2;
int rear=-1;
int front=-1;
void display()
{
	for(int i=front;i<=rear;++i)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}

void enqueue(int x)
{
	if(rear>=size-1)
	{
		printf("Over Flow");

	}else if(rear==-1 && front==-1)
	{
		rear=front=0;
		queue[rear]=x;
	}else
	{
		queue[++rear]=x;
	}
	display();
}

void dequeue()
{
	if(front ==-1 || front>rear)
	{
		printf("Under Flow");
	}else
	{
		front++;
	}
	display();
}


int main()
{	
	enqueue(12);
	enqueue(13);
	enqueue(14);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	return 0;
}
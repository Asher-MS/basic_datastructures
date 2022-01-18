#include<stdio.h>
#define MAX 3

int front=-1,rear=-1;
int queue[100];

void enqueue(int a)
{
	if(rear>MAX-1)
	{
		printf("Overflow\n");
	}else if(front==-1 && rear==-1)
	{
		rear++;
		front++;
		queue[rear]=a;	
	
	}else
	{
		rear=(rear+1)%MAX;
		queue[rear]=a;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("Empty Queue");
		
	}else if(front==rear)
	{
		
		front=rear=-1;
		
		
	}else
	{	
		
		front=(front+1)%MAX;
	}
}

void print_queue()
{
	if(front==-1 || rear==-1)
	{
		printf("The queue is empty\n");
	}else
	{
		int i=front;
		while(i!=rear)
		{
			printf("%d ",queue[i]);
			i=(i+1)%MAX;	
		}
		printf("%d ",queue[i]);

	}
}

int main()
{	
	int choice;

	while(1)
	{
		printf("\nEnter the choice \n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
		scanf("%i",&choice);
		switch(choice)
		{
			case 1:
			{
				int no;
				printf("Enter the number to insert");
				scanf("%d",&no);
				enqueue(no);
				print_queue();
				break;
			}
			case 2:
			{
				
				dequeue();
				printf("deleted\n");

				print_queue();
				break;
			}
			case 3:
			{
				print_queue();
				break;
			}
			case 4:
			{
				return 0;
				break;
			}
		}

	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *head = NULL;

struct node *front = NULL;
struct node *rear = NULL;

// void display()
// {
// 	struct node* temp=head;
// 	while(temp!=NULL)
// 	{
// 		printf("%d ",temp->data);
// 		temp=temp->link;
// 	}
// 	printf("\n");
// }

void enqueue(int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->link = NULL;
	if (front == NULL || rear == NULL)
	{
		front = rear = newnode;
	}
	else
	{
		rear->link = newnode;
		rear = newnode;
	}
}

int dequeue()
{
	if (front == NULL || rear == NULL)
	{
		printf("Queue is empty");
		return -1;
	}
	else
	{
		int val = front->data;
		front = front->link;
		return val;
	}
}

void display()
{
	printf("QUEUE:\n");
	struct node *temp = front;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

// void enqueue(int data)
// {
// 	struct node* newnode=(struct node*)malloc(sizeof(struct node));
// 	newnode->data=data;
// 	newnode->link=head;
// 	head=newnode;
// }

// int dequeue()
// {
// 	struct node* temp=head;
// 	int val=-1;
// 	if(temp==NULL)
// 	{
// 		printf("The Queue is empty\n");
// 	}else
// 	{
// 		if(head->link!=NULL)
// 		{
// 			while(temp->link->link!=NULL)
// 			{
// 				temp=temp->link;
// 			}
// 			val=temp->link->data;
// 			temp->link=NULL;

// 		}else
// 		{
// 			val=head->data;
// 			head=NULL;
// 		}
// 	}
// 	return val;
// }

int main()
{

	while (1)
	{

		int choice;
		printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{

		case 1:
		{
			int temp;
			printf("Enter the number to enqueue");
			scanf("%d", &temp);
			enqueue(temp);
			display();
			break;
		}
		case 2:
		{
			int temp = dequeue();
			if (temp != -1)
			{
				printf("%d Dequeued\n", temp);
			}
			display();
			break;
		}
		case 3:
		{
			return 0;
		}
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void display()
{
	struct node *temp = front;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

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

void push(int data)
{
	struct node *temp = top;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->link = NULL;
	if (top == NULL)
	{
		top = newnode;
	}
	else
	{
		newnode->link = top;
		top = newnode;
	}
}

int pop()
{
	if (top == NULL)
	{
		printf("Stack is empty");
		return -1;
	}
	else
	{
		int val = top->data;
		top = top->link;
		return val;
	}
}

void reverse()
{
	printf("Reversed Queue  ");
	while (front != NULL)
	{
		push(dequeue());
	}

	while (top != NULL)
	{
		enqueue(pop());
	}
	display();
	printf("\n");
}
int main()
{

	while (1)
	{

		int choice;
		printf("1.Enqueue\n2.Dequeue\n3.Reverse the Queue\n4.Exit\n");
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
			reverse();
			break;
		}
		case 4:
		{
			return 0;
		}
		}
	}
	return 0;
}
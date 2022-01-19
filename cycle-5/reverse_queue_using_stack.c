#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
};

struct node* head=NULL;
struct node* front=NULL;
struct node* rear=NULL;
// struct node* stack_head=NULL;
struct node* top=NULL;

void display()
{
	struct node* temp=front;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}


void add_end(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=data;	
	newnode->link=NULL;
	
	if(front==NULL && rear==NULL){
		front=newnode;
		rear=newnode;
	}
	else{
		rear->link=newnode;
		rear=rear->link;
	}	
}


int del_beg()
{
	int val=-1;
	if(front==NULL && rear==NULL){
		printf("Queue empty\n");
	}
	else if(front==rear){
		val=front->data;
		
		struct node* todel1=front;
		free(todel1);
		front=NULL;
		rear=NULL;
	}
	else
	{
		struct node* todel=front;
		val=todel->data;
		front=todel->link;
		free(todel);
	}
	return val;
}

void push(int data)
{
	struct node* temp=top;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
	if(top==NULL)
	{
		top=newnode;
	}else
	{
		newnode->link=top;
		top=newnode;
	}
	
	
}

int pop()
{
	if(top==NULL)
	{
		printf("Stack is empty");
		return -1;
	}else
	{
		int val=top->data;
		top=top->link;
		return val;
	}
}

void reverse()
{	
	printf("Reversed Queue  ");
	while(front!=rear)
	{
		// push(del_end());
		push(del_beg());
	}
	
	while(top!=NULL)
	{
		add_end(pop());
	}
	display();
	printf("\n");
}

int main()
{	
	while(1)
	{	
		int choice;
		printf("1.Enqueue\n2.Dequeue\n3.reverse\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				int temp;
				printf("Enter the number to enqueue");
				scanf("%d",&temp);
				// add_beg(temp);
				add_end(temp);
				display();
				break;
			}
			case 2:
			{
				// int temp=del_end();
				int temp=del_beg();
				if(temp!=-1)
				{
					printf("%d Dequeued\n",temp);
				}
				display();
				break;
			}
			case 3:
			{
				reverse();
			}
			case 4:
			{
				return 0;
			}
		}	
	}
	return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node* link;
};

struct node* head=NULL;
struct node* stack_head=NULL;




void display()
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}





void add_beg(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=head;
	head=newnode;
}





int del_end()
{
	struct node* temp=head;
	int val=-1;
	if(temp==NULL)
	{
		printf("The Queue is empty\n");
	}else
	{
		if(head->link!=NULL)
		{
			while(temp->link->link!=NULL)
			{
				temp=temp->link;
			}
			val=temp->link->data;
			temp->link=NULL;

		}else
		{
			val=head->data;
			head=NULL;
		}
	}
	return val;
}




void push(int data)
{
	struct node* temp=stack_head;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=data;
	
	newnode->link=NULL;
	
	if(temp!=NULL)
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;

	}else
	{	
		
		stack_head=newnode;
	}
}

int pop()
{
	struct node* temp=stack_head;
	int val=-1;
	if(temp==NULL)
	{
		printf("The Stack is empty\n");
	}else
	{
		if(stack_head->link!=NULL)
		{
			while(temp->link->link!=NULL)
			{
				temp=temp->link;
			}
			val=temp->link->data;
			temp->link=NULL;

		}else
		{
			val=stack_head->data;
			stack_head=NULL;
		}
	}
	return val;
}

void reverse()
{	
	printf("Reversed Queue  ");
	while(head!=NULL)
	{
		push(del_end());

	}
	
	while(stack_head!=NULL)
	{
		add_beg(pop());
	}
	display();
	printf("\n");
}
int main()
{
	
	
	
	while(1)
	{	
			


		int choice;
		printf("1.Enqueue\n2.Dequeue\n3.Reverse the Queue\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1:
			{
				int temp;
				printf("Enter the number to enqueue");
				scanf("%d",&temp);
				add_beg(temp);
				display();
				break;
			}
			case 2:
			{
				int temp=del_end();
				if(temp!=-1)
				{
					printf("%d Dequeued\n",temp);
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
*/
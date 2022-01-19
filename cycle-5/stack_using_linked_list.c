#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node* link;
};


struct node* top=NULL;


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


void display()
{	
	printf("STACK : ");
	struct node* temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

int main()
{
	while(1)
	{	
		int choice;
		printf("1.Push\n2.Pop\n3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				int temp;
				printf("Enter the value to push");
				scanf("%d",&temp);
				// add_end(temp);
				push(temp);
				display();
				break;

			}
			case 2:
			{
				int temp=pop();
				if(temp!=-1)
				{
					printf("%d Popped\n",temp);
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
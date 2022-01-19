#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node* link;
};

struct node* top=NULL;





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
	top=newnode;
}





int pop()
{
	struct node* temp=top;
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



int main()
{
	
	
	
	while(1)
	{	
			


		int choice;
		printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
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
				return 0;
			}
		}	
	}
	return 0;
}
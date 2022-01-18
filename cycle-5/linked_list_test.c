#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node* link;
};







void display(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}


void add_end(struct node* head,int data)
{
	struct node* temp=head;
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
		
		head=newnode;
	}
	printf("address in add_end function : %d\n",head);

	
}



int main()
{
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head=(struct node*)NULL;
	
	
	while(1)
	{	
			


		int choice;
		printf("1.Display\n2.Insert at End\n3.Insert at Beginning\n4.Delete from beginning\n5.Delete from end\n6.Insert into position\n7.Delete from position\n8.Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				display(head);
				break;
			}
			case 2:
			{
				int temp;
				printf("Enter the data");
				scanf("%d",&temp);
				printf("address in main function : %d\n",head);
				add_end(head,temp);
				
				

				break;
			}
			case 8:
			{
				return 0;
			}
		}	
	}
	return 0;
}
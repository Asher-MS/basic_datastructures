#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student
{
	int number;
	char name[20];
	int total_mark;
	struct student* link;

};

struct student* head;

void insert(int number,char name[],int total_mark)
{
	struct student* newnode=(struct student*)malloc(sizeof(struct student));
	struct student* temp=head;
	newnode->number=number;
	strcpy(newnode->name,name);
	newnode->total_mark=total_mark;
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
}


void delete()
{	
	struct student* temp=head;
	if(temp!=NULL)
	{
		if(temp->link==NULL)
		{
			head=NULL;
			return;
		}
		while(temp->link->link!=NULL)
		{	
			temp=temp->link;
		}
		
		temp->link=NULL;
	}else
	{
		printf("list is Empty");
	}
}

void search(int number)
{
	struct student* temp=head;
	if(temp!=NULL)
	{
		if(temp->number=number)
		{	
			printf("__________STUDENTS_________\n");
			printf("Student Found\n");
			printf("Number : %d\n",temp->number);
			printf("Name : %s\n",temp->name);
			printf("Total Mark :%d\n",temp->total_mark);
			printf("\n");
			printf("____________________________\n");
			return;

		}
		while(temp->link!=NULL)
		{	
			temp=temp->link;
		}
		

	}else
	{
		printf("The List is Empty");
	}
}


void sort()
{
	struct student* i=head;
	struct student* j;
	if(i!=NULL)
	{
		while(i!=NULL)
		{
			j=head;
			while(j->link!=NULL)
			{
				if(j->number>j->link->number)
				{
					int numbert=j->link->number;
					j->link->number=j->number;
					j->number=numbert;
					char namet[20];
					strcpy(namet,j->link->name);
					strcpy(j->link->name,j->name);
					strcpy(j->name,namet);
					int total_markt=j->link->total_mark;
					j->link->total_mark=j->total_mark;
					j->total_mark=total_markt;
				}
				j=j->link;
			}
			i=i->link;
		}
	}else
	{
		printf("The List is empty");
	}
}

void display()
{
	struct student* temp=head;
	printf("__________STUDENTS_________\n");
	if(head==NULL)
	{
		printf("The List is empty\n");
	}else
	{
		while(temp!=NULL)
		{
			printf("Number : %d\n",temp->number);
			printf("Name : %s\n",temp->name);
			printf("Total Mark :%d\n",temp->total_mark);
			printf("\n");
			temp=temp->link;
		}
	}
	printf("_________________________________\n");
}

int main()
{	
	while(1)
	{
		printf("Enter the Choise \n1.Insert\n2.Delete\n3.Search\n4.Sort\n5.Display\n6.Exit");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				int number;
				char name[20];
				int total_mark;
				printf("Enter the number");
				scanf("%d",&number);
				getchar();
				printf("Enter the name");
				gets(name);
				printf("Enter the total mark");
				scanf("%d",&total_mark);
				insert(number,name,total_mark);
				display();
				break;

			}
			case 2:
			{
				delete();
				display();
				break;
			}
			case 3:
			{
				printf("Enter the number to search");
				int number;
				scanf("%d",&number);
				search(number);
				break;

			}
			case 4:
			{
				sort();
				display();
				break;
			}
			case 5:
			{
				display();
				break;
			}
			case 6:
			{
				return 0;
			}
		}
	}
	return 0;
}



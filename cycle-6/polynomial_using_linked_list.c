#include<stdio.h>
#include<stdlib.h>

struct node
{
	int c;
	int e;
	struct node* link;
};

// struct node* head1=NULL;
// struct node* head2=NULL;


void insert(struct node** head,int coeff,int exp)
{
	
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	struct node* temp=*head;
	newnode->c=coeff;
	newnode->e=exp;
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
		*head=newnode;
	}
}

void display(struct node** head)
{
	struct node* temp=*head;
	while(temp!=NULL)
	{
		
		printf("%d^%d+",temp->c,temp->e);
		temp=temp->link;
	}
	printf("\n");

}

void input_poly(struct node** head)
{
	printf("Enter the size");
	int size;
	scanf("%d",&size);
	int coeff,exp;
	for(int i=0;i<size;++i)
	{
		printf("Enter the coefficient");
		scanf("%d",&coeff);
		printf("Enter the exponent");
		scanf("%d",&exp);
		
		insert(head,coeff,exp);
		
	}
}
void add_poly(struct node** head1,struct node** head2)
{
	
	struct node* result=NULL;
	struct node* temp1=*head1;
	struct node* temp2=*head2;

	while(temp1!=NULL || temp2!=NULL)
	{
		
		
		if(temp1==NULL)
		{
			
			insert(&result,temp2->c,temp2->e);
			temp2=temp2->link;
		}else if(temp2==NULL)
		{	
			
			insert(&result,temp1->c,temp1->e);
			temp1=temp1->link;
		}else if(temp1->e==temp2->e)
		{
			
			insert(&result,temp1->c+temp2->c,temp2->e);

			temp2=temp2->link;
			temp1=temp1->link;
		}else if(temp2->e>temp2->e)
		{
			
			insert(&result,temp2->c,temp2->e);
			temp2=temp2->link;
		}else
		{
			
			insert(&result,temp1->c,temp1->e);
			temp1=temp1->link;
		}
		
	}
	printf("The result is \n");
	display(&result);

}

int main()
{	
	struct node* head1=NULL;
	struct node* head2=NULL;
	printf("Input the first polynomail");
	input_poly(&head1);
	printf("Input the second polynomial");
	input_poly(&head2);
	
	
	add_poly(&head1,&head2);
	
	
	return 0;
}

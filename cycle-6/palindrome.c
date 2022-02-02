#include<stdio.h>
#include<stdlib.h>

struct node
{
	char c;
	struct node* next;
	struct node* prev;
};
struct node* head=NULL;
struct node* tail=NULL;

void push(char c)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	newnode->prev=NULL;
	newnode->c=c;
	if(head==NULL)
	{
		head=newnode;
		tail=newnode;
	}else
	{
		newnode->prev=tail;
		tail->next=newnode;
		tail=newnode;
	}
}


void display()
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%c ",temp->c);
		temp=temp->next;
	}
	printf("\n");
}

int palindrome_check()
{
	struct node* left=head;
	struct node* right=tail;
	while(left->c==right->c)
	{
		if(left==right)return 1;
		// printf("left : %c right : %c\n",left->c,right->c);
		left=left->next;
		right=right->prev;

	}
	return 0;
}

int main()
{
	
	char word[20];
	printf("Enter the word");
	gets(word);
	for(int i=0;word[i]!='\0';++i)
	{
		push(word[i]);
	}
	// display();
	if(palindrome_check())
	{
		printf("The word is palindrome");
	}else
	{
		printf("The word is not palindrome");
	}
	return 0;
}
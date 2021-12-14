#include<stdio.h>
#define size 10


int stack[size];
int top=-1;

void push(int x)
{
	if(top>=size-1)
	{
		printf("Stack is full");
	}else
	{
		top++;
		stack[top]=x;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("The Stack is empty");
		return -1;
	}else
	{
		
		return stack[top--];
	}
}
void print_stack()
{	
	printf("______STACK______\n");
	for(int i=top;i>=0;--i)
	{
		printf("%d\n",stack[i]);
	}
	printf("_________________\n\n");
}	
int main()
{
	int s;
	printf("Welcome to Stack land\n");
	while(1)
	{
		printf("\nEnter your operation\n1.push to stack\n2.pop from stack\n3.display the stack\n4.exit");
		scanf("%d",&s);
		switch(s)
		{
			case 1:
				{
					int item;
					printf("Enter the item to push");
					scanf("%d",&item);
					push(item);
					printf("\npush done\n");
					break;
				}
			case 2:
				{
					pop();
					printf("pop done");
					break;
				}	
			case 3:
				{
					print_stack();
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

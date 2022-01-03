#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
char stack[100];
int top=-1;


int prio(char c)
{
 	switch(c)
	{
		
		case '^':return 3;
		case '*':return 2;
		case '/':return 2;
		case '+':return 1;
		case '-':return 1;
		case '(':return 0;
	}
}
void push(int x)
{
	stack[++top]=x;	
}

int pop()
{
	if(top==-1)
	{
		printf("The stack is empty");
		exit(0);
	}else
	{
		return stack[top--];
	}

}

int main()
{	
	char in_ep[]="x+y*z/w+u";
	int length=9;
	int x;
	for(int i=0;i<length;++i)
	{	

		if((int)in_ep[i]>=97 && (int)in_ep[i]<=122)
		{
			printf("%c",in_ep[i]);	

		}else
		{	
			

			if(in_ep[i]=='(')
			{
				push(in_ep[i]);
			}else
			{
				if(in_ep[i]==')')
				{
					while(stack[top]!='(')
					{
						printf("%c",pop());
					}
					pop();// spend hours trying to find the problem and this was the solution
				}else
				{
					while(prio(stack[top])>=prio(in_ep[i]))
					{	
						// printf("Hurray");
						printf("%c",pop());
					}
					push(in_ep[i]);
				}
			}
		}	

	
	}
	while(top!=-1)printf("%c",pop());
	return 0;
}

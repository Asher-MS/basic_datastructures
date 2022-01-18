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
	char in_ep_r[]="(A-B/C)*(A/K-L)";

	int length=15;
	int x;
	char in_ep[100];

	char pre_ep[100];
	int pre_index=0;
	
	for(int i=0;i<length;++i)
	{	
		// printf("%c",in_ep_r[length-i-1]);
		if(in_ep_r[length-i-1]=='(')
		{
			in_ep[i]=')';
		}else if(in_ep_r[length-i-1]==')')
		{	
			// printf("came here");
			in_ep[i]='(';
		}else
		{
			in_ep[i]=in_ep_r[length-i-1];
		}
	}// The program upto reversing the string is correct

	// for(int i=0;i<length;++i)
	// {
	// 	printf("%c",in_ep[i]);
	// }
	// printf("End");

	for(int i=0;i<length;++i)
	{	
		// printf("%c",in_ep[i]);

		if((int)in_ep[i]>=97 && (int)in_ep[i]<=122)
		{
			// printf("%c",in_ep[i]);	
			pre_ep[pre_index++]=in_ep[i];


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
						// printf("%c",pop());
						pre_ep[pre_index++]=pop();
					}
					pop();// spend hours trying to find the problem and this was the solution
				}else
				{
					while(prio(stack[top])>prio(in_ep[i]))
					{	
						// printf("Hurray");
						// printf("%c",pop());
						pre_ep[pre_index++]=pop();
					}
					push(in_ep[i]);
				}
			}
		}	

	
	}
	while(top!=-1)
	{
		// printf("%c",pop());
		pre_ep[pre_index++]=pop();
	}
	for(int i=pre_index-1;i>=0;--i)
	{
		printf("%c",pre_ep[i]);
	}
	return 0;
}

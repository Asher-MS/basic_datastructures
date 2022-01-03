#include<stdio.h>
#include<math.h>
char stack[100];
int top=-1;

void push(char c)
{
	stack[++top]=c;
}

char pop()
{
	if(top==-1)
	{
		printf("The stack is emplty\n");
	}else
	{
		return stack[top--];
	}
}
char pos_exp[100];
int pos_exp_index=0;
void pos_exp_insert(char c)
{
	pos_exp[pos_exp_index++]=c;
}

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

int eval(int a,int b,char c)
{
	switch (c)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
		case '^':return pow(a,b);
	}
}

int vals[100];
int val_index=0;
int main()
{
	char in_ep[]="x+y*z/w+u";
	int length=9;
	for(int i=0;i<length;++i)
	{
		char inc=in_ep[i];
		if(inc>='a' && inc<='z')
		{
			pos_exp_insert(inc);
		}else
		{
			if(inc=='(')
			{
				push('(');
			}else
			{
				if(inc==')')
				{
					while(stack[top]!=')')pos_exp_insert(pop());
					pop();
				}else
				{
					while(prio(stack[top])>=prio(inc))
					{
						pos_exp_insert(pop());
					}
					push(inc);
				}
			}
		}
	}
	while(top!=-1)pos_exp_insert(pop());
	for(int i=0;i<pos_exp_index;++i)printf("%c",pos_exp[i]);
	printf("\n");

	for(int i=0;i<pos_exp_index;++i)
	{
		char inc=pos_exp[i];
		if(inc>='a' && inc<='z')
		{
			printf("Enter the value of %c",inc);
			scanf("%i",&vals[val_index++]);
		}else
		{
			vals[val_index-2]=eval(vals[val_index-2],vals[val_index-1],inc);
			val_index=val_index-1;
		}
		// printf("\n");
		// for(int j=0;j<val_index;++j)
		// {
		// 	printf("%d ",vals[j]);

		// }
		// printf("\n");


	}
	printf("The result is : %d\n",vals[0]);
	return 0;
}
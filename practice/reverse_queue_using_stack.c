#include<stdio.h>
#define size 5
// QUEUE
int queue[size];
int rev_queue[size];


int front=-1,rear=-1;
void enqueue(int d,int* queue)
{
	if(rear==size-1)
	{
		printf("Queue Overflow\n");
	}else
	{
		if(front==-1)front=0;
		queue[++rear]=d;
	}
}

int dequeue(int* queue)
{
	if(front==-1 || front>rear)
	{
		printf("Queue UnderFlow");
		return -1; 
	}else
	{
		return queue[front++];
	}
}



// STACK

int top=-1;
int stack[size];

void push(int d)
{
	if(top==size-1)
	{
		printf("Stack overflow");
	}else
	{
		stack[++top]=d;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("Stack UnderFlow");
		return -1;
	}else
	{
		return stack[top--];
	}
}

void reverse()
{
	while(front<=rear)
	{
		push(dequeue(queue));
	}
	while(top>=0)
	{
		enqueue(pop(),rev_queue);
	}
}
void display()
{
    printf("stack is \n");
    for (int i = 0; i <= top; i++)
        printf("%d\t", stack[i]);
    printf("\n");
}
void main()
{
     char ans;
    int ch;
    int n;
    do
    {
        printf("Queue Menu\n");
        printf("------------");
        printf("\n1.ENQUEUE 2.DEQUEUE 3.DISPLAY\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element\n");
            scanf("%d", &n);
            enqueue(n,queue);
            
            break;
        case 2:
            dequeue(queue);
            
            break;
        
        case 3:
            reverse();
            display();
            break;
        default:
            printf("you entered invalid choice\n");
            break;
        }
        printf("\ndo you wish to continue(y/n)\n");
        scanf(" %c", &ans);
    } while (ans == 'y' || ans == 'Y');
}
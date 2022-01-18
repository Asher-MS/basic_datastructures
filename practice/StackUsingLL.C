#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int value;
    Node* link;
}*top,*newnode,*temp;
int Push(Node* newnode)
{
    if(newnode==NULL)
        return 0;
    else if(top==NULL)
        top=newnode;
    else
    {
        newnode->link=top;
        top=newnode;
    }
    return 1;
    
}
Node* Pop()
{
    if(top==NULL)
        return NULL;
    else
    {
        temp=top;
        top=top->link;
        return temp;
    }
}
void Display()
{
    if(top==NULL)
        printf("Stack is empty!");
    else
    {
        temp=top;
        printf("\n\t\t--TOP--");
        while(temp->link!=NULL)
        {

            printf("\n%d",temp->value);
            temp=temp->link;//This line was absent before:)
        }
        printf("\n%d",temp->value);
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n\n\t\t\t\bStack Using Linked List\n\n\t\t\t\bMenu\n\t1.Push To Stack\n\t2.Pop Stack\n\t3.Display Stack\n\t4.Exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    newnode=(Node*) malloc (sizeof(Node));
                    printf("Enter the value to be pushed:");
                    scanf("%d",&(newnode->value));
                    newnode->link=NULL;
                    if(Push(newnode))
                        printf("\nNode pushed successfully.");
                    else
                        printf("\nFailed pushing due to an error.");
                    break;
            case 2:
                    temp=Pop();
                    if(temp!=NULL)
                        printf("\nValue Popped: %d",temp->value);
                    else
                        printf("Stack is already empty.Popping failed.");
                    break;
            case 3:
                    Display();
                    break;
            case 4:exit(0);
        }
    }
}
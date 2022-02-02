#include<stdio.h>
#include<stdlib.h>


int ind=0;
int* arr;
void insert(int data)
{	
	arr=(int*)realloc(arr,(ind+1)*(sizeof(int)));
	arr[ind++]=data;
}

void delete()
{
	ind--;
}

void display()
{
	printf("Array  : ");
	for(int i=0;i<ind;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{

	// int size;
	
	// printf("Enter the size");
	// scanf("%d",&size);
	arr=(int*)malloc(sizeof(int));
	while(1)
	{
		printf("Enter choice\n1.Insert\n2.Delete\n3.Exit");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				int temp;
				printf("Enter the data");
				scanf("%d",&temp);
				insert(temp);
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
				return 0;
			}
		}
	}

	return 0;
}



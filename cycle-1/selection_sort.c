#include<stdio.h>

int main()
{
	int a[10],length;
	printf("Enter the length");
	scanf("%d",&length);
	printf("Enter the Array");
	for(int i=0;i<length;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<length-1;++i)
	{
		int min=i;
		for(int j=i+1;j<length;++j)
		{
			if(a[j]<a[min])min=j;
		}
		int temp;
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}






	printf("The Sorted array is \n");
	for(int i=0;i<length;++i)
	{
		printf("%d ",a[i]);
	}

}

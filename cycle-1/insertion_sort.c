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
	for(int i=0;i<length;++i)
	{
		int temp=a[i];
		int j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("The Sorted array is \n");
	for(int i=0;i<length;++i)
	{
		printf("%d ",a[i]);
	}

}

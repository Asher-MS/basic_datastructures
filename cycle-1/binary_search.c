#include<stdio.h>


int main()
{	
	int a[10],key,length;
	printf("Enter the length");
	scanf("%d",&length);
	printf("Enter the array");
	for(int i=0;i<length;++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the key to search");
	scanf("%d",&key);
	int low=0,high=length-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			printf("Element Found at position %d",mid);
			return 0;
		}else
		{
			if(a[mid]>key)
			{
				high=mid-1;
			}else
			{
				low=mid+1;
			}
		}
	}
	printf("Element not Found");
	return 0;
}

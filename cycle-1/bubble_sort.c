#include <stdio.h>

int main()
{
    int arr[10], length;
    printf("Enter the Size of the array");
    scanf("%d", &length);
    for (int i = 0; i < length; ++i)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
			{
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
        }
    }
	printf("the sorted array is\n");
	for(int i=0;i<length;++i)
	{
		printf("%d ",arr[i]);
	}
}

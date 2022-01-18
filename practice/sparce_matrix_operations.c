#include<stdio.h>

struct tuple
{
	int i;
	int j;
	int val;
} t1[100],t2[100];
int t1_index=1,t2_index=1;
int main()
{
	int r1,c1,r2,c2;
	printf("Enter the dimensions of the first matrix\n");
	scanf("%d %d",&r1,&c1);
	printf("Enter the elements of the first matrix");
	for(int i=0;i<r1;++i)
	{
		for(int j=0;j<c1;++j)
		{
			int temp;
			scanf("%d",&temp);
			if(temp)
			{
				t1[t1_index].i=i;
				t1[t1_index].j=j;
			}
		}
	}
}



#include<stdio.h>


struct poly
{
	int e;
	int c;
};


int main()
{
	struct poly p1[100];
	struct poly p2[100];
	struct poly result[100];
	int p1_index=0,p2_index=0,r_index=0;
	int l1,l2;
	printf("Enter the length of the first polynomail\n");
	scanf("%d",&l1);
	printf("Enter the length of the second polynomail\n");
	scanf("%d",&l2);
	printf("Enter the elements of the first polynomail\n");
	for(int i=0;i<l1;++i)
	{
		printf("Enter the exponent\n");
		scanf("%d",&p1[i].e);
		printf("Enter the coefficient\n");
		scanf("%d",&p1[i].c);
	}
	printf("Enter the elements of the second polynomail\n");
	for(int i=0;i<l1;++i)
	{
		printf("Enter the exponent\n");
		scanf("%d",&p2[i].e);
		printf("Enter the coefficient\n");
		scanf("%d",&p2[i].c);
	}

	while(p1_index<l1 || p2_index<l2)
	{
		if(p1_index>l1)
		{
			result[r_index]=p2[p2_index];
			p2_index++;
			r_index++;
		}else if(p2_index>l2)
		{
			result[r_index]=p1[p1_index];
			p1_index++;
			r_index++;
		}else if(p1[p1_index].e==p2[p2_index].e)
		{
			result[r_index].e=p1[p1_index].e;
			result[r_index].c=p2[p2_index].c+p1[p1_index].c;
			r_index++;
			p1_index++;
			p2_index++;
		}else if(p1[p1_index].e>p2[p2_index].e)
		{
			result[r_index]=p1[p1_index];
			r_index++;
			p1_index++;
		}else
		{
			result[r_index]=p2[p2_index];
			r_index++;
			p2_index++;
		}

	}

	printf("The result is ");
	for(int i=0;i<r_index;++i)
	{
		printf("%d^%d+",result[i].c,result[i].e);
	}

}
#include<stdio.h>


struct poly
{
	int exponent;
	float coefficient;
};
void read_poly(struct poly *p,int n)
{
	printf("Enter the polynomial");	
	for(int i=0;i<n;++i)
	{
		printf("Enter the exponent");
		scanf("%d",&p[i].exponent);
		printf("%d",p[i].exponent);
		printf("Enter the coefficient");
		scanf("%f",&p[i].coefficient);
	}
}

void print_poly(struct poly *p,int n)
{
	for(int i=0;i<n;++i)
	{
		printf("%d^%f+",p[i].coefficient,p[i].exponent);
	}
}
int main()
{
	struct poly polynomial1[10];
	struct poly polynomial2[10];
	int t1,t2;
	struct poly result[20];
	printf("Enter the sizes of the polynomials");
	scanf("%d %d",&t1,&t2);
	read_poly(polynomial1,t1);
	print_poly(polynomial1,t1);
	read_poly(polynomial2,t2);
	int ind1=0,ind2=0,indr=0;
	while(ind1<t1 || ind2<t2)
	{
		if(ind1==t1)
		{	
			result[indr].exponent=polynomial2[ind2].exponent;
			result[indr].coefficient=polynomial2[ind2].coefficient;
			indr++;
			ind2++;
		}
		if(ind2==t2)
		{
			result[indr].exponent=polynomial1[ind1].exponent;
			result[indr].coefficient=polynomial1[ind1].coefficient;
			indr++;
			ind1++;
		}
		if(polynomial1[ind1].exponent==polynomial2[ind2].exponent)
		{
			result[indr].exponent=polynomial1[ind1].exponent;
			result[indr].coefficient=polynomial1[ind1].coefficient+polynomial2[ind2].coefficient;
			indr++;
			ind1++;
			ind2++;
		}else if(polynomial1[ind1].exponent>polynomial2[ind2].exponent)
		{
			result[indr].exponent=polynomial1[ind1].exponent;
			result[indr].coefficient=polynomial1[ind1].coefficient;
			indr++;
			ind1++;
			
		}else
		{
			result[indr].exponent=polynomial2[ind2].exponent;
			result[indr].coefficient=polynomial2[ind2].coefficient;
			indr++;
			ind2++;
		}
			
		

	}
	print_poly(result,indr);
}

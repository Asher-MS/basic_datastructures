#include<stdio.h>


int main()
{
	int r=3,c=3;
	int arr[][3]={{0,0,0},{12,0,0},{0,0,0}};
	int tuple_mat[100][3];
	int tuple_mat_index=1;
	tuple_mat[0][0]=r;
	tuple_mat[0][1]=c;
	
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			if(arr[i][j]!=0)
			{
				tuple_mat[tuple_mat_index][0]=i;
				tuple_mat[tuple_mat_index][1]=j;
				tuple_mat[tuple_mat_index][2]=arr[i][j];
				tuple_mat_index++;
			}
		}
	}
	tuple_mat[0][2]=tuple_mat_index-1;
	for(int i=0;i<tuple_mat_index;++i)
	{
		printf("%d %d %d\n",tuple_mat[i][0],tuple_mat[i][1],tuple_mat[i][2]);
	}
	return 0;
}

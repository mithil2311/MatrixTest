#include<iostream>
using namespace std;
int main()
{
	int n,i,j,temp,mat[100][100];
	printf("enter the order of the matrix you want to enter");
	scanf("%d",&n);
	printf("enter the elements of the matrix");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("The given matrix is as follows:");
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1)
			{
				printf("%d",mat[i][j]);
				printf("\n");	
				
			}
			else
			{
				printf("%d",mat[i][j]);
				printf("\t");
			}
		}
	}
	printf("The 90 degree clockwise rotated matrix is:\n");
	for(i=0;i<n/2;i++)
	{
		for(j=i;j<n-1-i;j++)
		{
			temp=mat[i][j];
			mat[i][j]=mat[n-1-j][i];
			mat[n-1-j][i]=mat[n-1-i][n-1-j];
			mat[n-1-i][n-1-j]=mat[j][n-1-i];
			mat[j][n-1-i]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1)
			{
				printf("%d",mat[i][j]);
				printf("\n");	
			}
			else
			{
				printf("%d",mat[i][j]);
				printf("\t");
			}
		}
	}
	return 0;
}

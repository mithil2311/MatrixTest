#include<stdio.h>
int main()
{
	int a[10][10],i,j,k,m,n;
	printf("\nenter the no of rows and columns"); /*taking input for number of rows and number of columns*/
	scanf("%d %d",&m,&n);
	printf("\n the matrix is"); /*taking the elements of the matrix row-wise*/
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
printf("the anti clockwise matrix is\n"); /*printing the matrix anti-clockwise at an angle 90 degree*/
for(i=n;i>=1;i--){
	for(j=1;j<=m;j++)
	printf("%d\t",a[j][i]);
	printf("\n");
}

	return 0;
	
}

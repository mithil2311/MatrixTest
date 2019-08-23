#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
/*Program to find the determinant of any nxn matrix*/

int** reduction(int **mat,int n, int j); //declaring functions at the start
double determinant(int **mat,int n);

int main(){
	int n; //n stores order of the matrix
	cout<<"Order of matrix"<<endl;
	cin>>n;
	cout<<"Enter elements of the matrix"<<endl;
	int **mat=new int*[n]; // Initialization of 2D array
	for(int x=0;x<n;x++)
	{
		mat[x]=new int[n]; //Creating n 1D array rows 
		for(int y=0;y<n;y++)
		{
			cin>>mat[x][y]; // Taking user inputed elements for the matrix
			
		}
	}
		cout<<"Determinant = "<<determinant(mat,n)<<endl; // Final value of determinant is returned here		
	return 0;
}
// reduction function reduces a nxn matrix to a (n-1)x(n-1) matrix excluding the ith row and jth column in the process
int** reduction(int **mat,int n, int j){
	int **newmat=new int*[n-1];
	for(int x=0,a=0;x<n && a<n-1;x++)//a and b keep count of reduced matrix's indexing
	{
		newmat[x]=new int[n-1];
		if(x!=0){// we calculate determinant using the first row always
		
	    for(int y=0,b=0;y<n && b<n-1;y++)
		{
			if(y!=j)
			{
		    	newmat[a][b]=mat[x][y];
			    b++;
	     	}
		}
		a++;}
	}
	return newmat;// returning the 2D reduced array
}
// determinant is a recursive function to calculate the determinant till a 2x2 matrix is found
double determinant(int **mat,int n){
	double det=0.0;
	int j;// keeps track of column index 
	if(n==2){
		double d=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);//2x2 matrix formula
		return d;
	}
	else{
		for(j=0;j<n;j++){
			det=det + (pow(-1,j))*mat[0][j]*determinant(reduction(mat,n,j),n-1);//nxn matrix determinant formula where n>2
		}
	}
return det;
}

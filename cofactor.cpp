#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
//this is a test comment
/*Program to find the determinant of any nxn matrix*/
//test one

int** Reduction(int **mat,int n,int i, int j);
double Determinant(int **mat,int n);
int main(){
	int n,i,j;
	double Cofactor;
	cout<<"Order of matrix"<<endl;
	cin>>n;
	cout<<"Enter the index to find cofactor: "<<endl;
	cout<<"i:";
	cin>>i;
	cout<<"j:";
	cin>>j;
	cout<<"Enter elements of the matrix"<<endl;
	int **mat=new int*[n];    
// x and y are used to denote the indices of matrix.
	for(int x=0;x<n;x++)
	{
		mat[x]=new int[n];
		for(int y=0;y<n;y++)
		{
			cin>>mat[x][y];
			
		}
	}
/* Cofactor is determinant of matrix reduced by deleting the ith row, j'th column and multiplied by (-1)^(i+j). */
    if(n==2)
    
      Cofactor=pow(-1,(i+j))*mat[2-i][2-j];
    	
    else
      Cofactor= pow(-1,(i+j))*Determinant(Reduction(mat,n,i-1,j-1),n-1);
	  cout<<"cofactor is: "<<Cofactor<<endl;
				
	return 0;
}

/* @ Reduction() returns the reduced matrix after deleting a row and a column given as parameter.
   @param mat : The original matrix.
   @param n : The order of matrix.
   @param i: The row number to be deleted.
   @param j: The column number to deleted.
   @ret matrix: Reduced matrix.
*/   

int** Reduction(int **mat,int n,int i, int j){
/*
   A new matrix named NewMat is created of order one less than the order of original matrix mat,
   and all the elements of mat except of ith row and jth column is assigned to new matrix NewMat.
*/ 
	int **NewMat=new int*[n-1];
	for(int x=0,a=0;x<n && a<n-1;x++)
	{
		NewMat[x]=new int[n-1];
		if(x!=i){
		
	    for(int y=0,b=0;y<n && b<n-1;y++)
		{
			if(y!=j)
			{
		    	NewMat[a][b]=mat[x][y];
			    b++;
	     	}
		}
		a++;}
	}
	return NewMat;
}
/* 
@Determinant () returns the determinant of matrix given as parameter.
@param mat: The matrix whose determinant is to be calculated.
@param n: Order of matrix.
@ret double value: determinant of matrix.
*/ 

double Determinant(int **mat,int n){
/*
 For 2x2 matrix determinant can be easily calculated using the formula.
   For any other matrix of order more than 2, determinant can be calculated by calling the Determinant 
   function again (i.e.,using recursion) and each time reducng the matrix.
   and finally multiplying it by each column's elements of first row and using sign convention. 
*/    
	double determinant=0.0;
	if(n==2){
		double det=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
		return det;
	}
	else{
		for(int c=0;c<n;c++){
		
			determinant=determinant + (pow(-1,c))*mat[0][c]*Determinant(Reduction(mat,n,0,c),n-1);
		
		}
	}
return determinant;
}

#include<stdio.h>
#include <stdlib.h>

#include "FindRref.c"
#include "PrintMatrix.c"
#include "InternalNeed.c"
#include "ForSolution.c"
#include "CreateNullSpace.c"
#include "InteralNull.c"


void freeThePointer(float** ,int);
int main(){
		int m,n,i,j,k,r=0;
		float **matrix;//Not in Augmented form
		float b[m];//solution for the same
        printf("Enter No. Rows:\n");
        scanf("%d",&m);
        printf("Enter No. of Columns:\n");
        scanf("%d",&n);
        matrix = malloc(sizeof(int*) * m); 
     
    	for(i = 0; i < m; i++) {
        	matrix[i] = malloc(sizeof(int*) * n);//Create m*n Space
    	}
        printf("Enter coefficients Row vise:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                scanf("%f",&matrix[i][j]);
            }
        }
		printf("Enter solutions as b:\n");

            for (j = 0; j < m; j++) {
                scanf("%f",&b[j]);
            }
    	// By follow the method of finding solution...
    	// 1) Convert the matrix in rref form
    	// 2) By comparing variable value, take desicion wether it have unique, infinit or no solution
        
    	r=upperTraingularForm(matrix, b,n, m,r); 
        if(n>m){
        	int z=calculateNumOfZeroRow(matrix,b,m, n);
        	if(z==0){
        		r++;
			}
    	}    	
        printf("Rank Of The Matrix:%d \n",r);
       /* printf("Upper Traingular:\n");
        printMatrix(matrix,b,m,n);     
        */
        rrefForm(matrix,b, n, m);
        printf("RREF:\n");   // rref form
        printMatrix(matrix,b,m,n);
        findSolution( matrix,b,m,n);  // print the solutions
        int N=n-r;
        generateNullSpace(matrix, r, n,m); //Null space calculation
        freeThePointer(matrix, m);
	
}
void freeThePointer(float** pointer,int m){
	int i;
	for(i = 0; i < m; i++) {
        	free(pointer[i]);
    	}
    	free(pointer);

}


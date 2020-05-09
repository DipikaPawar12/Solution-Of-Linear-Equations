//Main File is "SolutionOfLinearEquationMain.c" Please run that file
// To print any 2D matrix with its soltion (as augmented form)
void printMatrix(float **matrix,float b[],int m,int n){
	int i,j;
	for ( i = 0; i < m; i++) {
            for ( j = 0; j < n; j++) {
            	if(matrix[i][j]==-0.00000){
            		matrix[i][j]=0.00000;
				}
                printf("%f ", matrix[i][j]);
            }
            printf ("|%f \n",b[i]);
        }
}
// To print only 2D matrix
void print(float **null,int n,int N){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<N;j++){
			if(null[i][j]==-0.00000){
            		null[i][j]=0.00000;
				}
			printf("%f ",null[i][j]);
		}
		printf("\n");
	}
}

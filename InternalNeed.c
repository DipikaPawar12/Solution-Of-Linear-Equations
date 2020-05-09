//Main File is "SolutionOfLinearEquationMain.c" Please run that file

// Find non zero pivot
int findNonZeroPivot(float **matrix, int zeroPivotRow, int index,int m) {
	int i;
        for ( i = zeroPivotRow + 1; i < m; i++) {
            if (matrix[i][index] != 0) {
                return i;
            }
        }
        return -1;
}

//Do row exchange if pivot wasn't there
void rowExchange(float **matrix,float b[], int row1, int row2,int n) {
    float swap,sw;
    int i;
    for (i = 0; i <n; i++) {
        swap = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = swap;      
    }
    sw=b[row1];
    b[row1]=b[row2];
    b[row2]=sw;
}

//Calculate number of zero rows
// To neglate them for calculation
int calculateNumOfZeroRow(float **matrix,float b[],int m,int n){
	int i,j,count=0,zero=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matrix[i][j]==0){
				count++;
			}
			
		}
		if(count==n&& b[i]==0 ){
			zero++; 
		}else if(count==n){
			return -1;
		}	
		count=0;
	}
	return zero;
}
// Find the first non zero row to swap
void checkZeroRows(float** matrix,float b[],int m,int n){
	int i,j,count=0;
	int lastRow=m-1;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matrix[i][j]==0){
				count++;
			}
			
		}
		if(count==n){
				rowExchange(matrix, b,i, lastRow,n);
				lastRow--;
		}
		if(i==lastRow){
			break;
		}
		count=0;
	}
}

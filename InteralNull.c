//Main File is "SolutionOfLinearEquationMain.c" Please run that file
//Convert matrix in upper triangular
void upperTraingularFormAgain(float**matrix,int n,int m){
	int tp,i,j,k;
	float pivot, temp;
    float c[m];
    if(n>m){
        tp=m-1;
        }
        else{
            tp=n;
        }
        for (i = 0; i <tp; i++) {
            pivot = matrix[i][i];
            if(pivot == 0) {
                int exchangeWith = findNonZeroPivot(matrix, i, i,m);
                if (exchangeWith != -1) {
                     rowExchange(matrix, c,i, exchangeWith,n);
                    pivot = matrix[i][i];
                } else {
                    continue;
                }
            }
            for ( k = i + 1; k < m; k++) {
                temp = (float) matrix[k][i];
                for ( j = 0; j < n; j++) {
                    matrix[k][j] += ((-1) * matrix[i][j] * temp) / pivot;
                }                
            }
        }
}

//RREF form

void rrefFormAgain(float** matrix, int n, int m){
	int tp,i,j,k;
	float temp,pivot;
	if(n>m){
            tp=m;
        }
        else{
            tp=n;
        }
        for (i = tp-1; i >=0; i--) {
            pivot = matrix[i][i];
            if (pivot == 0) {
                continue;
            }
			for(j=0;j<n;j++){
			
				matrix[i][j]/=pivot;
			}if(i!=0){				
	            for (k = i - 1; k >= 0; k--) {
	                temp = (float) matrix[k][i];
	                for ( j = 0; j < n; j++) {
	                    matrix[k][j] += ((-1) * matrix[i][j] * temp);
	                }
	               
	            }
        	}
        }
}  
//swap the columns as neccesary
void columnExchange(float **matrix, int column1, int column2,int m) {
        float swap;
        int i;
        for (i = 0; i <m; i++) {
            swap = matrix[i][column1];
            matrix[i][column1] = matrix[i][column2];
            matrix[i][column2] = swap;            
        }
}

//non zero pivot finder
int findNonZroPivot(float **matrix, int zeroPivotColumn, int index,int n) {
	int i;
        for ( i = zeroPivotColumn + 1; i <n; i++) {
            if (matrix[index][i] != 0) {
                return i;
            }
        }
        return -1;
}

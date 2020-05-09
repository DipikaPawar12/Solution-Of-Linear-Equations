//Main File is "SolutionOfLinearEquationMain.c" Please run that file
int upperTraingularForm(float**matrix,float b[],int n,int m,int r){
	int tp,i,j,k;
	float pivot, temp;
    if(n>m){
        tp=m-1;
    }
    else{
        tp=n;
    }        
    for (i = 0; i <tp; i++) {
        pivot = matrix[i][i];
    	if (pivot == 0) {
            int exchangeWith = findNonZeroPivot(matrix, i, i,m);
            if (exchangeWith != -1) {
                rowExchange(matrix, b,i, exchangeWith,n);
                pivot = matrix[i][i];
            } else {
              	 continue;                   
            }

        }
		r++;
        for ( k = i + 1; k < m; k++) {
            temp = (float) matrix[k][i];
            for ( j = 0; j < n; j++) {
                matrix[k][j] += ((-1) * matrix[i][j] * temp) / pivot;
        	}
            b[k]+=(-1)*(temp)*b[i]/pivot;    
        }
    }
		return r;
}
void rrefForm(float** matrix,float b[], int n, int m){
	int tp,i,j,k;
	float temp,pivot;
	if(n>m){
            tp=m;
        }
        else{
            tp=n;
    	}
    for (i = tp-1; i > 0; i--) {
        pivot = matrix[i][i];
        if (pivot == 0) {
            continue;
        }
		for(j=0;j<n;j++){	
			matrix[i][j]/=pivot;
		}
		b[i]/=pivot;
        for (k = i - 1; k >= 0; k--) {
            temp = (float) matrix[k][i];
            for ( j = 0; j < n; j++) {
                matrix[k][j] += ((-1) * matrix[i][j] * temp);
            }
            b[k]+=(-1)*(temp)*b[i];      
        }
	}
}  


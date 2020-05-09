//Main File is "SolutionOfLinearEquationMain.c" Please run that file

// solution of equations
void findSolution(float** matrix,float b[],int m,int n){
	int i,j,k,zero;
	checkZeroRows(matrix,b, m, n);
	zero=calculateNumOfZeroRow(matrix,b,m, n);
	if(zero==-1){
		printf("Solution doesn't exist...\n"); // means left side is zero but right side have some non-zero value
	}
	else if(m-zero==n){  // No zero rows.. means each have pivots
		printf("Unique Solution: ");
		uniqueSolution( b, m,zero);
	}
	else{
		printf("Infinte Solution:\n");
		infinteSolution(matrix,b, m, n, zero);
	}
}

//unique answer
void uniqueSolution(float b[],int m,int zero){
	int i;
	printf("\n(");
	for(i=0;i<m-zero;i++){
		printf("%f  ",b[i]);
	}
	printf(")\n");
}

//particular solution
void infinteSolution(float **matrix,float b[],int m,int n,int zero){
	int i,j;
	float variable[n],a=0;
	for(i=0;i<n;i++){
		variable[i]=-2001;
	}
	int noOfFreeVariable=n-m-zero,nonZero=0,z=0,k;
	int temp=n-1;
	for(i=m-1-zero;i>=0;i--){
		for(j=0;j<n;j++){
			if(matrix[i][j]!=0){
				temp=j;
				break;
			}
		}
		nonZero=0;
		for(j=0;j<n;j++){
			if(j!=temp){			
				a+=matrix[i][j];
				if(matrix[i][j]!=0)
					nonZero++;
			}
		}
		if(a==0&&nonZero==0){
			variable[i]=b[i];
		}
		else {
			z=n-1;
			
			for(k=nonZero;k>0;k--){
				if(variable[z]==-2001 && z!=temp){	//Hopefully b[i] can't be -2001		
					variable[z]=1;
					noOfFreeVariable--;
				}	
				z--;				
			}	
			a=0;
			for(j=temp+1;j<n;j++){
				a+=variable[j]*matrix[i][j];			
			}
			variable[temp]=(b[i]-a)/matrix[i][temp];			
		}
	}
	printf("(");
	for(i=0;i<n;i++){
		printf("%f ",variable[i]);
	}
	printf(")\n");
}

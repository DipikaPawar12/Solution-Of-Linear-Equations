//Main File is "SolutionOfLinearEquationMain.c" Please run that file
void generateNullSpace(float **matrix,int r,int n,int m){
	float **null;//Generate Null Space
    null= malloc(sizeof(int*) * n);
    int i,j,k=0;
    int N=n-r;
	for(i = 0; i < n; i++) {
       	null[i] = malloc(sizeof(int*) * (n-r));
   	}
   	int exchange[r],l=0;
   	rrefFormAgain( matrix, n, m);//For first row
   	for(i=0;i<r;i++){
   		if(matrix[i][i]==0){
   			int exchangeWith=findNonZroPivot(matrix,i,i, n);
   			if (exchangeWith != -1) {
                columnExchange(matrix,i,exchangeWith,m);
                exchange[l]=(i+1)*10+(exchangeWith+1);                   
                l++;
                upperTraingularFormAgain(matrix, n, m);
                rrefFormAgain( matrix, n, m);
            } else {
                continue;
                }
		}
	}
   	float F[r][N];
   	float identityNull[N][N];
   	//Take values
   	k=0;
   	for(i=0; i<r;i++){
   		for(j=r;j<n;j++){
   				F[i][k]=matrix[i][j];
   				k++;
		   }
		k=0;
	   }
   	for(i=0;i<N;i++){
   		for(j=0;j<N;j++){
   			if(i==j){
   				identityNull[i][j]=1;
			}
			else
   				identityNull[i][j]=0;
		 
		}
	}
	//Give NUll Space
	
   	for(i=0;i<r;i++){
   		for(j=0;j<N;j++){
   				null[i][j]=-F[i][j];
		   }
	   }
	k=0;
   	for(i=r;i<n;i++){
   		for(j=0;j<N;j++){
   				null[i][j]=identityNull[k][j];
		   }
		k++;
	   }
	   
	i=0;
	while(l>0){//If Column were exchange
		float c[n];
		int row1=exchange[i]%10;
		int row2=exchange[i]/10;
		rowExchange(null, c,row2-1, row1-1,N);
		i++;
		l--;
	}
	int count=0;
	for(i=0;i<n;i++){
		for(j=0;j<N;j++){
			if(null[i][j]==0){
				count++;
			}
		}
	}
	if(count==n*(N) ){
		printf("\nNull Space is null\n");
	}else{
		printf("Null Space contains vectors multiple of:\n");
		print(null,n,N);
	}
freeThePointer(null, n);
}

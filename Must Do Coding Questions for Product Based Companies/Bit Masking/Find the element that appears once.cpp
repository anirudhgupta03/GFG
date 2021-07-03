public:	
	int search(int A[], int N){
	    
	    int xorSum = 0;
	    
	    for(int i = 0; i < N; i++){
	        xorSum ^= A[i];
	    }
	    
	    return xorSum;
	}
};

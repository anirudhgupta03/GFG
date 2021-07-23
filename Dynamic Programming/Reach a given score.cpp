class Solution{	
  
  vector<int> v = {3,5,10};
	
	long long dp[4][n+1];
	
	for(int i = 0; i <= 3; i++){
	    for(int j = 0; j <= n; j++){
	        
	        if(j == 0){
	            dp[i][j] = 1;
	        }
	        else if(i == 0){
	            dp[i][j] = 0;
	        }
	        else if(v[i-1] <= j){
	            dp[i][j] = dp[i][j-v[i-1]] + dp[i-1][j];
	        }
	        else{
	            dp[i][j] = dp[i-1][j];
	        }
	    }
	}
	return dp[3][n];
};

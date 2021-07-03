//Ref: https://www.youtube.com/watch?v=aZuQXkO0-XA
class Solution{
	public:
	int MinSquares(int n)
	{
	    int dp[n+1];
	    
	    dp[0] = 0;
	    dp[1] = 1;
	    
	    for(int i = 2; i <= n; i++){
	        
	        int temp = INT_MAX;
	        
	        for(int j = 1; j * j <= i; j++){
	            int rem = i - j*j;
	            
	            if(dp[rem] < temp){
	                temp = dp[rem];
	            }
	        }
	        
	        dp[i] = temp + 1;
	    }
	    
	    return dp[n];
	}
};

//Recursive Approach
//Time Complexity - O(2^M)
//Space Complexity - O(1)
class Solution{
	public:
	int solve(int M, int V, int coins[]){
	    
	    if(V == 0){
	        return 0;
	    }
	    if(M == 0){
	        return INT_MAX - 1;
	    }
	    
	    if(coins[M-1] <= V){
	        return min(solve(M,V-coins[M-1],coins) + 1, solve(M-1,V,coins));
	    }
	    else{
	        return solve(M-1,V,coins);
	    }
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    int a = solve(M,V,coins);
	    
	    if(a == INT_MAX - 1){
	        return -1;
	    }
	    return a;
	} 
	  
};

//Top-Down Approach
//Time Complexity - O(M*V)
//Space Complexity - O(1)
class Solution{	
	public:
	int solve(int M, int V, int coins[], vector<vector<int>> &dp){
	    
	    if(V == 0){
	        return dp[M][V] = 0;
	    }
	    if(M == 0){
	        return dp[M][V] = INT_MAX - 1;
	    }
	    
	    if(dp[M][V] != -1){
	        return dp[M][V];
	    }
	    
	    if(coins[M-1] <= V){
	        return dp[M][V] = min(solve(M,V-coins[M-1],coins,dp) + 1, solve(M-1,V,coins,dp));
	    }
	    else{
	        return dp[M][V] = solve(M-1,V,coins,dp);
	    }
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    
	    int a = solve(M,V,coins,dp);
	    
	    if(a == INT_MAX - 1){
	        return -1;
	    }
	    return a;
	} 
	  
};

//Bottom-Up Approach
//Time Complexity - O(M*V)
//Space Complexity - O(1)
class Solution{
	
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1, vector<int>(V+1));
	    
	    for(int i = 0; i <= M; i++){
	        for(int j = 0; j <= V; j++){
	            
	            if(i == 0 && j == 0){
	                dp[i][j] = 0;
	            }
	            else if(i == 0){
	                dp[i][j] = INT_MAX - 1;
	            }
	            else if(j == 0){
	                dp[i][j] = 0;
	            }
	            else if(coins[i-1] <= j){
	                dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    if(dp[M][V] == INT_MAX - 1){
	        return -1;
	    }
	    return dp[M][V];
	}
	  
};

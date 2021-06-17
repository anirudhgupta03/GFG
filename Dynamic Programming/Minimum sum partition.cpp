//Recursive Approach
//Time Complexity - O(2^N)
//Space Complexity - O(1)
class Solution{
  public:
    int solve(int ind, int temp, int sum, int arr[], int n){
        
        if(ind == n){
            return abs(sum-2*temp);
        }
        
        return min(solve(ind+1,temp+arr[ind],sum,arr,n), solve(ind+1,temp,sum,arr,n));
    }
    int minDifference(int arr[], int n)  { 
	    
	int sum = 0;
	    
	for(int i = 0; i < n; i++){
	     sum += arr[i];
	}
	    
	int temp = 0;
	    
	return solve(0,temp,sum,arr,n);
    } 
};

//Top-Down Approach
//Time Complexity - O(N*sum)
//Space Complexity - O(N*sum)
class Solution{
  public:
    int solve(int n, int temp, int sum, int arr[], vector<vector<int>> &dp){
        
        if(n == 0){
            return dp[n][temp] = abs(sum-2*temp);
        }
        
        if(dp[n][temp] != -1){
            return dp[n][temp];
        }
        
        return dp[n][temp] = min(solve(n-1,temp+arr[n-1],sum,arr,dp), solve(n-1,temp,sum,arr,dp));
    }
    int minDifference(int arr[], int n)  { 
	    
	int sum = 0;
	    
	for(int i = 0; i < n; i++){
	    sum += arr[i];
	}
	    
	int temp = 0;
	    
	vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    
	return solve(n,temp,sum,arr,dp);
    } 
};


//Bottom-Up Approach
//Time Complexity - O(N*sum)
//Space Complexity - O(N*sum)
class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum = 0;
	    
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    
	    int dp[n+1][sum+1];
	    for(int i = 0; i < n + 1; i++){
	        dp[i][0] = 1;
	    }
	    for(int j = 1; j < sum + 1; j++){
	        dp[0][j] = 0;
	    }
	    
	    for(int i = 1; i < n + 1; i++){
	        for(int j = 1; j < sum + 1; j++){
	            
	            if(arr[i-1] <= j){
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    vector<int> v;
	    
	    for(int j = 0; j <= sum/2; j++){
	        if(dp[n][j]){
	            v.push_back(j);
	        }
	    }
	    
	    int mindiff = INT_MAX;
	    for(int i = 0; i < v.size(); i++){
	        mindiff = min(mindiff,sum - 2*v[i]);
	    }
	    
	    return mindiff;
	} 
};

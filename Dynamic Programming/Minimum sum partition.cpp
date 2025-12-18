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
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i - 1][j];
                    if(arr[i - 1] <= j){
                        dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
                    }
                }
            }
		}
        int minDiff = INT_MAX;
        for(int j = 0; j <= sum/2; j++){
            int s1 = j, s2 = sum - j;
            if(dp[n][s1]){
                minDiff = min(minDiff, abs(s1 - s2));
            }
        }
        return minDiff;
    }
};

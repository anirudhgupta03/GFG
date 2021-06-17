//Recursive Approach
//Time Complexity - O(2^N)
//Space Complexity - O(1)
class Solution{
public:
    bool isPresent(int ind, int sum, int N, int arr[]){
        
        if(sum == 0){
            return true;
        }
        if(ind == N){
            return false;
        }
        
        if(arr[ind] <= sum){
            return isPresent(ind+1,sum-arr[ind],N,arr) || isPresent(ind+1,sum,N,arr);
        }
        else{
            return isPresent(ind+1,sum,N,arr);
        }
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += arr[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        sum /= 2;
        
        return isPresent(0,sum,N,arr);
    }
};

//Top-Down Approach
//Time Complexity - O(N*sum)
//Space Complexity - O(N*sum)
class Solution{
public:
    bool isPresent(int sum, int N, int arr[], vector<vector<int>> &dp){
        
        if(N == 0 && sum == 0){
            return dp[N][sum] = 1;
        }
        if(N == 0){
            return dp[N][sum] = 0;
        }
        if(sum == 0){
            return dp[N][sum] = 1;
        }
        
        if(dp[N][sum] != -1){
            return dp[N][sum];
        }
        
        if(arr[N-1] <= sum){
            return dp[N][sum] = isPresent(sum-arr[N-1],N-1,arr,dp) || isPresent(sum,N-1,arr,dp);
        }
        else{
            return dp[N][sum] = isPresent(sum,N-1,arr,dp);
        }
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += arr[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        sum /= 2;
        
        vector<vector<int>> dp(N+1,vector<int>(sum+1,-1));
        
        return isPresent(sum,N,arr,dp);
        
    }
};

//Bottom-Up Approach
//Time Complexity - O(N*sum)
//Space Complexity - O(N*sum)
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += arr[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        sum /= 2;
        
        vector<vector<int>> dp(N+1,vector<int> (sum+1));
        
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= sum; j++){
                
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = 0;
                }
                else if(j == 0){
                    dp[i][j] = 1;
                }
                else if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
};

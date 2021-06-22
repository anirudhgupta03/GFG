//Recurisve Approach
class Solution{
public:
    int solve(int arr[], int i, int j){
        
        if(i >= j){
            return 0;
        }
        int mn = INT_MAX;
        
        for(int k = i; k <= j - 1; k++){
            
            int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            mn = min(mn,tempans);
        }
        return mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1, j = N - 1;
        return solve(arr,i,j);
    }
};

//Top-Down Approach
//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
class Solution{
public:
    
    int solve(int arr[], int i, int j, vector<vector<int>> &dp){
        
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int mn = INT_MAX;
        
        for(int k = i; k <= j-1; k++){
            int temp = solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
            
            mn = min(mn,temp);
        }
        
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N + 1,vector<int>(N + 1));
        
        for(int i = 0; i < N + 1; i++){
            for(int j = 0; j < N + 1; j++){
                dp[i][j] = -1;
            }
        }
        return solve(arr,1,N-1,dp);
    }
};

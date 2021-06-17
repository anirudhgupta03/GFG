//Recursive Approach
//Time Complexity - O(2^N)
//Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int n, int x, vector<int> &arr){
    
    
    if(x == 0){
        return 1;
    }
    
    if(ind == n){
        return 0;
    }
    
    if(arr[ind] <= x){
        return solve(ind+1,n,x-arr[ind],arr) + solve(ind+1,n,x,arr);
    }
    else{
        return solve(ind+1,n,x,arr);
    }
}
int main() {
    
    int n;
    cin >> n;
    
    std::vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x;
    cin >> x;
    
    cout << solve(0,n,x,arr) << endl;
    
    return 0;
}

//Top-Down Approach
//Time Complexity - O(N*x)
//Space Complexity - O(N*x)
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, vector<int> &arr, vector<vector<int>> &dp){
    
    
    if(n == 0 && x == 0){
        return dp[n][x] = 1;
    }
    
    if(n == 0){
        return dp[n][x] = 0;
    }
    
    if(x == 0){
        return dp[n][x] = 1;
    }
    
    if(arr[n - 1] <= x){
        return dp[n][x] = solve(n-1,x-arr[n-1],arr,dp) + solve(n-1,x,arr,dp);
    }
    else{
        return dp[n][x] = solve(n-1,x,arr,dp);
    }
}
int main() {
    
    int n;
    cin >> n;
    
    std::vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x;
    cin >> x;
    
    vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    
    cout << solve(n,x,arr,dp) << endl;
    
    return 0;
}

//Bottom-Up Approach
//Time Complexity - O(N*x)
//Space Complexity - O(N*x)
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int dp[n+1][B+1];
    
    for(int j = 1; j <= B; j++){
        dp[0][j] = 0;
    }
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= B; j++){
            
            if(A[i-1] <= j){
                dp[i][j] = dp[i-1][j-A[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][B];
}

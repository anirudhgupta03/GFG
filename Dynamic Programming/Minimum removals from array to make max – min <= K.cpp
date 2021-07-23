#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, int arr[], int k, vector<vector<int>> &dp){
    
    if(l > r){
        return 0;
    }
    if(arr[r] - arr[l] <= k){
        return 0;
    }
    
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    
    int ans = INT_MAX - 1;
    ans = min(ans, solve(l+1,r,arr,k,dp) + 1);
    ans = min(ans, solve(l,r-1,arr,k,dp) + 1);
    
    return dp[l][r] = ans;
}
int main() {
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int k;
    cin >> k;
    
    sort(arr,arr+n);
    
    int minRemovals;
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    minRemovals = solve(0,n-1,arr,k,dp);
    
    cout << minRemovals << endl;
	return 0;
}

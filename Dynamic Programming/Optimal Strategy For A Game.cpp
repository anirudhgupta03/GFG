//Function to find the maximum possible amount of money we can win.
#define ll long long
ll solve(int l, int r, int arr[], int n, vector<vector<int>> &dp){
    
    if(l > r){
        return 0;
    }
    
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    ll a = arr[l] + solve(l+2,r,arr,n,dp);
    ll b = arr[l] + solve(l+1,r-1,arr,n,dp);
    
    ll c = arr[r] + solve(l+1,r-1,arr,n,dp);
    ll d = arr[r] + solve(l,r-2,arr,n,dp);
    
    return dp[l][r] = max(min(a,b), min(c,d));
}
long long maximumAmount(int arr[], int n) 
{
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solve(0,n-1,arr,n,dp);
}

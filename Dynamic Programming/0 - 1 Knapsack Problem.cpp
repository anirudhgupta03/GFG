int dp[1001][1001];

int knapsack(int W, int wt[], int val[], int n) 
{
    if(n == 0 || W == 0){
       return 0;
   }
   
   if(dp[W][n] != -1){
       return dp[W][n];
   }
   if(wt[n-1] <= W){
       return dp[W][n] = max( val[n-1] + knapsack(W-wt[n-1], wt, val, n-1) , 
                   knapsack(W,wt,val,n-1));
   }
   else{
       return dp[W][n] = knapsack(W, wt, val, n-1);
   }
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
   memset(dp,-1 ,sizeof(dp));
   return knapsack(W,wt,val,n);
}

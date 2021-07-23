//https://www.codingninjas.com/codestudio/problems/count-the-number-of-subsequences-having-product-not-more-than-p_1214647?leftPanelTab=0
//Ref: https://www.youtube.com/watch?v=iOjV84903WA
#include<bits/stdc++.h>
using namespace std;

int countSubsequences(vector < int > & arr, int n, int k) {
    
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
    
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (arr[j - 1] <= i && arr[j - 1] > 0)
 
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
        }
    }
    return dp[k][n];
}

//Application of Catalan Number
class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    #define ll long long
    int numTrees(int N) 
    {
        if(N == 1 || N == 2){
            return N;
        }
        
        int mod = 1e9 + 7;
        
        ll dp[N+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= N; i++){
            
            int l = 0, r = i - 1;
            
            while(l <= i - 1){
                dp[i] = (dp[i] + (dp[l]*dp[r])%mod)%mod;
                l++;
                r--;
            }
        }
        
        return dp[N];
    }
};

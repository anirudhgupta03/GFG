//Ref1: https://www.youtube.com/watch?v=vlbA8oUxSV0
//Ref2: https://www.youtube.com/watch?v=L5lBTrCC99I
class Solution{
public:
    /*You are required to complete below method */
    int mod;
    long long solve(int i, int j, vector<vector<long long>> &dp, string &str){
        
        if(i > j) return 0;
        
        if(i == j) return 1;
        
        if(dp[i][j] != -1){
            return dp[i][j]%mod;
        }
        
        if(str[i] == str[j]){
            return dp[i][j] = (solve(i + 1, j, dp, str)%mod + solve(i, j - 1, dp, str)%mod + 1)%mod;
        }
        else{
            return dp[i][j] = (solve(i + 1, j, dp, str)%mod + solve(i, j - 1, dp, str)%mod - solve(i + 1, j - 1, dp, str)%mod + mod)%mod;
        }
    }
    long long int  countPS(string str)
    {
        int n = str.size();
        
        vector<vector<long long>> dp(n, vector<long long>(n,-1));
        
        mod = 1e9 + 7;
        
        return (solve(0, n - 1, dp, str))%mod;
    }
     
};

class Solution{
public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n1 = pattern.size(), n2 = str.size();
        
        int dp[n1 + 1][n2 + 1];
        
        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n2; j++){
                
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = 0;
                }
                else if(j == 0){
                    if(pattern[i-1] == '*'){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                    if(pattern[i-1] == '*'){
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                    else if(pattern[i-1] == '?'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(pattern[i-1] == str[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};

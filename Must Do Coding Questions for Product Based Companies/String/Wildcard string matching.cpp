class Solution{
public:
    bool match(string wild, string pattern)
    {
        int len1 = wild.size(), len2 = pattern.size();
        
        int dp[len1 + 1][len2 + 1];
        
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = 0;
                }
                else if(j == 0){
                    if(wild[i-1] == '*'){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else if(wild[i-1] == pattern[j-1] || wild[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(wild[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[len1][len2];
    }
};

//Time Complexity - O(len^2)
//Space Complexity - O(len^2)
class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        
        string rev = s;
        reverse(rev.begin(),rev.end());
        
        int len = s.size();
        
        int dp[len+1][len+1];
        
        for(int i = 0; i <= len; i++){
            for(int j = 0; j <= len; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s[i-1] == rev[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return len - dp[len][len];
    } 
};

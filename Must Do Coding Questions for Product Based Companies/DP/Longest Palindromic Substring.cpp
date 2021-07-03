class Solution{   
public:
    string longestPalindrome(string S){
        
        int n = S.size();
        
        string dp[n][n];
        
        string LPS;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = "";
            }
        }
        LPS = S[0];
        for(int i = 0; i < n; i++){
            dp[i][i] = S[i];
        }
        
        bool flag = false;
        for(int i = 0; i < n - 1; i++){
            if(S[i] == S[i+1]){
                
                string temp;
                temp.push_back(S[i]);
                temp.push_back(S[i+1]);
                if(!flag){
                    LPS = temp;
                    flag = true;
                }
                dp[i][i+1] = temp;
            }
        }
        
        for(int i = n - 3; i >= 0; i--){
            for(int j = i + 2; j < n; j++){
                
                if(S[i] == S[j] && dp[i+1][j-1] != ""){
                    dp[i][j] = S[i] + dp[i+1][j-1] + S[j];
                    if(dp[i][j].size() >= LPS.size()){
                        LPS = dp[i][j];
                    }
                }
                else{
                    dp[i][j] = "";
                }
            }
        }
        return LPS;
    }
};

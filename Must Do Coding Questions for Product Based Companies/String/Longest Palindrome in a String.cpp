class Solution{
public:
    string longestPalin (string S) {
        
        int n = S.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        int maxLen = 1;
        string ans;
        ans.push_back(S[0]);
        
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        
        bool flag = false;
        
        for(int i = 0; i < n - 1; i++){
            if(S[i] == S[i+1]){
                dp[i][i+1] = 1;
                if(!flag){
                    maxLen = 2;
                    ans.clear();
                    ans.push_back(S[i]);
                    ans.push_back(S[i+1]);
                    flag = true;
                }
            }
        }
        
        for(int i = n - 3; i >= 0; i--){
            for(int j = i + 2; j < n; j++){
                if(S[i] == S[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    if(j - i + 1 >= maxLen){
                        maxLen = j - i + 1;
                        ans = S.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        
        unordered_set<string> dict;
        
        for(int i = 0; i < B.size(); i++){
            dict.insert(B[i]);
        }
        
        int n = A.size();
        
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                string s = A.substr(j,i-j+1);
                if(dict.find(s) != dict.end()){
                    
                    if(j == 0){
                        dp[i] = 1;
                    }
                    else{
                        dp[i] = dp[j-1];
                    }
                }
            }
        }
        
        return dp[n-1];
    }
};

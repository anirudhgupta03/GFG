// User function Template for C++
//Top-Down
//TC: O(N*N*N)
//SC: O(N*N*2) + Auxilliary Stack Space
// User function Template for C++
class Solution {
  public:
    int findWays(int i, int j, int exp, string &s, vector<vector<vector<int>>> &dp){
        
        if(i > j) return 0;
        
        if(i == j){
            if(s[i] == 'T'){
                if(exp) return 1;
                else return 0;
            }
            else{
                if(exp) return 0;
                else return 1;
            }
        }
      
        if(dp[i][j][exp] != -1){
            return dp[i][j][exp];
        }

        int count = 0;
        for(int k = i; k <= j; k++){
            int lT = findWays(i, k - 1, true, s, dp);
            int rT = findWays(k + 1, j, true, s, dp);
            int lF = findWays(i, k - 1, false, s, dp);
            int rF = findWays(k + 1, j, false, s, dp);
            
          if(s[k] == '|'){
                if(exp) count += lT * rT + lT * rF + lF * rT;
                else count += lF * rF;
            }
            else if(s[k] == '&'){
                if(exp) count += lT * rT;
                else count += lT * rF + lF * rT + lF * rF;
            }
            else if(s[k] == '^'){
                if(exp) count += lT * rF + lF * rT;
                else count += lT * rT + lF * rF;
            }
        }
        return dp[i][j][exp] = count;
    }
    int countWays(string &s) {
        // code here
        vector<int> ops;
        int len = s.length();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(2, -1)));        
        return findWays(0, len - 1, 1, s, dp);
    }
};

//Bottom-Up
//TC: O(N*N*N)
//SC: O(N*N*2)
// User function Template for C++
class Solution {
  public:
    int countWays(string &s) {
        // code here
        vector<int> ops;
        int len = s.length();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(len + 1, vector<int>(2, 0)));
        
        for(int i = 0; i < len; i++){
            if(s[i] == 'T'){
                dp[i][i][1] = 1;
            }
            else{
                dp[i][i][0] = 1;
            }
        }
        
        for(int i = len - 1; i >= 0; i--){
            for(int j = i + 1; j <= len - 1; j++){
                int count1 = 0, count2 = 0;
                for(int k = i; k <= j; k++){
                    if(k - 1 < 0) continue;
                    int way1 = dp[i][k - 1][1] * dp[k + 1][j][1];
                    int way2 = dp[i][k - 1][1] * dp[k + 1][j][0];
                    int way3 = dp[i][k - 1][0] * dp[k + 1][j][1];
                    int way4 = dp[i][k - 1][0] * dp[k + 1][j][0];
                    if(s[k] == '|'){
                        count1 += way1 + way2 + way3;
                        count2 += way4;
                    }
                    else if(s[k] == '&'){
                        count1 += way1;
                        count2 += way2 + way3 + way4;
                    }
                    else if(s[k] == '^'){
                        count1 += way2 + way3;
                        count2 += way1 + way4;
                    }
                }
                dp[i][j][1] = count1;
                dp[i][j][0] = count2;
            }
        }
        return dp[0][len - 1][1];
    }
};

//Recursion + Optimization
class Solution {
  public:
    int findPerfectSum(int ind, vector<int>& arr, int target, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(ind == -1 || target < 0) return 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        return dp[ind][target] = findPerfectSum(ind - 1, arr, target - arr[ind], dp) + findPerfectSum(ind - 1, arr, target, dp);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int zeros = 0;
        vector<int> v;
        for(int &ele: arr){
            if(ele == 0){
                zeros++;
            }
            else{
                v.push_back(ele);
            }
        }
        vector<vector<int>> dp(v.size(), vector<int>(target + 1, -1));
        return findPerfectSum(v.size() - 1, v, target, dp) * pow(2, zeros);
    }
};

//Tabulation
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int zeros = 0;
        vector<int> v;
        for(int &ele: arr){
            if(ele == 0){
                zeros++;
            }
            else{
                v.push_back(ele);
            }
        }
      
        vector<vector<int>> dp(v.size() + 1, vector<int>(target + 1, 0));
        for(int i = 0; i <= v.size(); i++){
            for(int j = 0; j <= target; j++){
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i - 1][j];
                    if(v[i - 1] <= j){
                        dp[i][j] += dp[i - 1][j - v[i - 1]];
                    }
                }
            }
        }
        return dp[v.size()][target]*pow(2, zeros);
    }
};

//Tabulation + Space Optimization
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int zeros = 0;
        vector<int> v;
        for(int &ele: arr){
            if(ele == 0){
                zeros++;
            }
            else{
                v.push_back(ele);
            }
        }
      
        vector<int> dp(target + 1, 0);
        for(int i = 0; i <= v.size(); i++){
            vector<int> currdp(target + 1, 0);
            for(int j = 0; j <= target; j++){
                if(j == 0){
                    currdp[j] = 1;
                }
                else if(i == 0){
                    currdp[j] = 0;
                }
                else{
                    currdp[j] = dp[j];
                    if(v[i - 1] <= j){
                        currdp[j] += dp[j - v[i - 1]];
                    }
                }
            }
            dp = currdp;
        }
        return dp[target]*pow(2, zeros);
    }
};

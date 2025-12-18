class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = 0;
        
        vector<int> vec;
        int zeros = 0;
        
        for(int &ele: arr){
            if(ele == 0){
                zeros++;
            }
            else{
                vec.push_back(ele);
            }
            sum += ele;
        }
        
        if((sum + diff)%2 != 0) return 0;
        
        int psum = (sum + diff)/2;
        
        int n = vec.size();
        vector<vector<int>> dp(n + 1, vector<int>(psum + 1, 0));
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= psum; j++){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(vec[i - 1] <= j){
                        dp[i][j] = dp[i - 1][j - vec[i - 1]] + dp[i - 1][j];
                    }
                    else{
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][psum]*pow(2, zeros);
    }
};

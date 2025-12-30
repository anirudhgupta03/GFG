class Solution {
  public:
    vector<int> findLIS(int n, vector<int> &nums){
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
    vector<int> findLDS(int n, vector<int> &nums){
        vector<int> dp(n, 1);
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> lis = findLIS(n, nums);
        vector<int> lds = findLDS(n, nums);
      
        int ans = 0;
        for(int i = 1; i <= n - 2; i++){
            if(lis[i] != 1 && lds[i] != 1){
                ans = max(ans, lis[i] + lds[i] - 1);
            }
        }
        return ans;
    }
};

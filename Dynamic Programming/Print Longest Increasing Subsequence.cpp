//Ref: https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
//Method - 1
class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        // Code here
        int n = nums.size();
        vector<int> dp[n];
        for(int i = 0; i < n; i++){
            dp[i] = {nums[i]};
        }
        int ansInd = 0, ansLen = 1;
        for(int i = 1; i < n; i++){
            int maxLenInd = -1, maxLen = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j].size() > maxLen){
                        maxLen = dp[j].size();
                        maxLenInd = j;
                    }
                }
            }
            if(maxLenInd != -1){
                vector<int> res = dp[maxLenInd];
                res.push_back(nums[i]);
                dp[i] = res;
            }
            if(dp[i].size() > ansLen){
                ansInd = i;
                ansLen = dp[i].size();
            }
        }
        return dp[ansInd];
    }
};

//Method - 2
class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        // Code here
        
        int n = nums.size();
        
        vector<int> dp(n, 1), hash(n);
        
        for(int i = 0; i < n; i++){
            hash[i] = i;
        }

        int ansInd = 0, ansLen = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > ansLen){
                ansLen = dp[i];
                ansInd = i;
            }
        }

        vector<int> res;
        while(hash[ansInd] != ansInd){
            res.push_back(nums[ansInd]);
            ansInd = hash[ansInd];
        }
        res.push_back(nums[ansInd]);
        reverse(res.begin(), res.end());
      
        return res;
    }
};

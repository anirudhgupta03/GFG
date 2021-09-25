class Solution {
public:
    int solve(int ind, vector<int> nums, int space, int k, vector<vector<int>> &dp){
        
        if(ind == nums.size()){
            return 0;
        }
        
        if(dp[ind][space] != -1){
            return dp[ind][space];
        }
        
        int cost = INT_MAX;
        
        if(space  == 0){
            if(space + nums[ind] <= k){
                cost = min(cost, solve(ind + 1, nums, space + nums[ind], k, dp));
            }
        }
        else{
            if(space + nums[ind] + 1 <= k){
                cost = min(cost, solve(ind + 1, nums, space + nums[ind] + 1, k, dp));
            }
        }
        if(space != 0){
            cost = min(cost, solve(ind, nums, 0, k, dp) + (k - space)*(k - space));
        }
        return dp[ind][space] = cost;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        vector<vector<int>> dp(nums.size(), vector<int>(k+1,-1));
        
        return solve(0, nums, 0, k, dp);
    } 
};

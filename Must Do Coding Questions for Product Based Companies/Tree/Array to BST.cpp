class Solution{
public:
    void solve(int l, int r, vector<int> &nums, vector<int> &res){
        
        if(l > r){
            return;
        }
        int mid = (l + r)/2;
        res.push_back(nums[mid]);
        
        solve(l,mid-1,nums,res);
        solve(mid+1,r,nums,res);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        
        vector<int> res;
        solve(0,nums.size()-1,nums,res);
        return res;
    }
};

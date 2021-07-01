//Time Complexity - O(N)
//Space Complexity - O(N)
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long> res(n);
        
        if(n == 1){
            res[0] = 1;
            return res;
        }
        vector<long long> left(n), right(n);
        
        left[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            left[i] = nums[i]*left[i-1];
        }
        
        right[n-1] = nums[n-1];
        
        for(int i = n - 2; i >= 0; i--){
            right[i] = nums[i]*right[i+1];
        }
        
        for(int i = 0; i < n; i++){
            
            if(i == 0){
                res[i] = right[i+1];
            }
            else if(i == n - 1){
                res[i] = left[i-1];
            }
            else{
                res[i] = left[i-1]*right[i+1];
            }
        }
        
        return res;
    }
};

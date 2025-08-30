//Ref: https://www.youtube.com/watch?v=frf7qxiN2qU
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> umap;
        int sum = 0;
        umap[0] = -1;
        
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(umap.find(sum) == umap.end()){
                umap[sum] = i;
            }
            
            if(umap.find(sum - k) != umap.end()){
                ans = max(ans, i - umap[sum - k]);
            }
        }
        return ans;
    }
};

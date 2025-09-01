class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int ans = 0, sum = 0;
        unordered_map<int,int> umap;
        umap[0] = -1;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(umap.find(sum) != umap.end()){
                ans = max(ans, i - umap[sum]);
            }
            else{
                umap[sum] = i;
            }
        }
        return ans;
    }
};

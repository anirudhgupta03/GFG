class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<long,long> umap;
        long xorSum = 0;
        long ans = 0;
        umap[0] = 1;
        for(int num: arr){
            xorSum ^= num;
            if(umap.find(xorSum ^ k) != umap.end()){
                ans += umap[xorSum ^ k];
            }
            umap[xorSum]++;
        }
        return ans;
    }
};

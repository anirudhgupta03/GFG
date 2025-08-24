class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int> umap;
        
        for(int i: arr){
            umap[i]++;
        }
        
        vector<vector<int>> res;
        
        for(int i: arr){
            if(umap[i]){
                res.push_back({i, umap[i]});
                umap[i] = 0;
            }
        }
        
        return res;
    }
};

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int, unordered_set<int>> umap;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(matrix[i][j] == 1 && matrix[i][k] == 1){
                        if(umap.find(j) != umap.end() && umap[j].find(k) != umap[j].end()){
                            return true;
                        }
                        umap[j].insert(k);
                    }
                }
            }
        }
        return false;
    }
};

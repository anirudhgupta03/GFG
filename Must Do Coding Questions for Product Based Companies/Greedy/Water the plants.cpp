class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int> v(n, -1);
        
        for(int i = 0; i < n; i++){
            if(gallery[i] == -1) continue;
            int start = max(0, i - gallery[i]), end = min(n - 1, i + gallery[i]);
            for(int j = start; j <= end; j++){
                v[j] = max(v[j], end);
            }
        }
        
        int ind = 0, count = 0;
        while(ind != n){
            if(v[ind] == -1){
                return -1;
            }
            count++;
            ind = v[ind] + 1;
        }
        return count;
    }
};

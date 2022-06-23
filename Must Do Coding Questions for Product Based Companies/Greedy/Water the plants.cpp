//Method - 1
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

//Method - 2
//Optimal Solution
//Ref: https://www.youtube.com/watch?v=D_0QMx9GXjg
class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> range;
        
        for(int i = 0; i < n; i++){
            if(gallery[i] == -1) continue;
            int start = max(0, i - gallery[i]);
            int end = min(n - 1, i + gallery[i]);
            range.push_back({start, end});
        }
        
        sort(range.begin(), range.end());
        
        int pos = 0, ind = 0, taps = 0;
        
        while(pos < n){
            int end = -1;
            while(ind < range.size() && range[ind].first <= pos){
                end = max(end, range[ind].second);
                ind++;
            }
            if(end < pos){
                return -1;
            }
            pos = end + 1;
            taps++;
        }
        return taps;
    }
};

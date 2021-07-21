public:
    int findSetBitCount(int n){
        
        int count = 0;
        while(n){
            count++;
            n = (n & (n-1));
        }
        return count;
    }
    bool static cmp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second == p2.second){
            return 0;
        }
        return p1.second > p2.second;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++){
            int c = findSetBitCount(arr[i]);
            v.push_back({arr[i],c});
        }
        
        stable_sort(v.begin(),v.end(),cmp);
        
        for(int i = 0; i < n; i++){
            arr[i] = v[i].first;
        }
    }

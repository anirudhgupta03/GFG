class Solution{
    public:
    #define ll long long
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(),a.end());
        
        ll diff = INT_MAX;
        
        for(ll i = 0; i <= n - m; i++){
            
            if(a[i+m-1] - a[i] < diff){
                diff = a[i+m-1] - a[i];
            }
        }
        return diff;
    }
};
  

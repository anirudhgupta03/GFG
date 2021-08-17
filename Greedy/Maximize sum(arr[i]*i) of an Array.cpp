class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        
        long long ans = 0, mod = 1e9 + 7;
        
        for(long long i = 0; i < n; i++){
            
            ans = (ans + (long long)i*a[i])%mod;
        }
        
        return ans;
    }
};

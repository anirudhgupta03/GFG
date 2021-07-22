class Solution{
    public:
    
    #define ll long long
    long long countWays(int n, int k){
        
        int mod = 1e9 + 7;
        
        if(n == 1){
            return k;
        }
        
        ll same = k*1;
        ll diff = k * (k-1);
        
        ll total = same + diff;
        
        for(int i = 3; i <= n; i++){
            same = diff*1;
            diff = total*(k-1);
            total = (same + diff)%mod;
        }
        
        return total;
    }
};

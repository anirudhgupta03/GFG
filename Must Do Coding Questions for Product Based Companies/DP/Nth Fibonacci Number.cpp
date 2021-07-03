class Solution{
public:
    long long int nthFibonacci(long long int n){
        
        int mod = 1e9 + 7;
        
        if(n == 1 || n == 2){
            return 1;
        }
        long long val1 = 1, val2 = 1, val3;
        
        for(int i = 3; i <= n; i++){
            val3 = (val1 + val2)%mod;
            val1 = val2;
            val2 = val3;
        }
        
        return val3;
    }
};

class Solution{
public:
#define ll long long
    int countBits(int N, long long int A[])
    {
        ll count = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < 32; i++){
            
            ll c = 0;
         
            for(int j = 0; j < N; j++){
                
                if((A[j] & (1 << i)) != 0){
                    c++;
                }
            }
            
            count += (c)*(N-c);
        }
        return (2*count)%mod;
    }
};

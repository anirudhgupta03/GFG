class Solution{
public: 
    long long int largestPrimeFactor(int N){
        
        if(N <= 3){
            return N;
        }
        vector<long long> prime(N+1,0);
        
        for(int p = 2; p*p <= N; p++){
            
            if(prime[p] == 0){
              
                for(int i = p*p; i <= N; i += p){
                    prime[i] = 1;
                }
            }
        }
        int ans;
        for(int i = 2; i <= N; i++){
            
            if(N % i == 0 && prime[i] == 0){
                ans = i;
            }
        }
        return ans;
    }
};

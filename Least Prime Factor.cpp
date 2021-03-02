class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        
        vector<int> prime(n+1,1);
        
        for(int p = 2; p*p <= n; p++)
        {
            if(prime[p] == 1){
                prime[p] = p;
                for(int i = p*p; i <= n; i+=p){
                    if(prime[i] == 1) prime[i] = p;
                }
            }
        }
        vector<int> v(n+1);
        
        for(int i = 1; i <= n; i++){
            if(prime[i] == 1) v[i] = i;
            else v[i] = prime[i];
        }
        return v;
    }
};

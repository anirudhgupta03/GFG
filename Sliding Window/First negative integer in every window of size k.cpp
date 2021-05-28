#define ll long long
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
                                                 
        ll i = 0, j = 0;
      
        vector<ll> res;
        
        queue<ll> q;
        
        while(j < N){
            
            if(A[j] < 0){
                q.push(A[j]);
            }
            
            if(j - i + 1 < K){
                j++;
            }
            else if(j - i + 1 == K){
                
                if(!q.empty()){
                    res.push_back(q.front());
                    if(q.front() == A[i]){
                        q.pop();
                    }
                }
                else{
                    res.push_back(0);
                }
                i++;
                j++;
            }
        }
        return res;                                         
 }

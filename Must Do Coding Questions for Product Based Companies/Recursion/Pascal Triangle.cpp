class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        
        int mod = 1e9 + 7;
        
        vector<vector<ll>> v;
        
        for(int i = 0; i <= n - 1; i++){
            
            vector<ll> temp;
            
            for(int j = 0; j <= i; j++){
                
                if(j == 0 || j == i){
                    temp.push_back(1);
                }
                else{
                    temp.push_back((v[i-1][j] + v[i-1][j-1])%mod);
                }
            }
            
            v.push_back(temp);
        }
        
        return v[n-1];
    }
};

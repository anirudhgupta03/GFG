class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) {
        
        int mod = 1e9 + 7;
        
        int ele = *max_element(a.begin(),a.end());
        
        vector<long long> v(ele + 1);
        
        v[0] = 1;
        
        for(int i = 1; i <= ele; i++){
            v[i] = (i*v[i-1])%mod;
        }
        
        vector<long long> res;
        
        for(int i = 0; i < n; i++){
            res.push_back(v[a[i]]);
        }
        
        return res;
    }
};

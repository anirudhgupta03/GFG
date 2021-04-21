#define ll long long
class Solution
{
    public:
    long long getMaxArea(long long arr[], int n){
        
        vector<ll> nsl;

        nsl.push_back(-1);
        
        stack<pair<ll,ll>> s;
        
        s.push({arr[0],0});
        
        for(ll i = 1; i < n; i++){
            
            if(s.top().first < arr[i]){
                nsl.push_back(s.top().second);
            }
            else{
                
                while(!s.empty() && s.top().first >= arr[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    nsl.push_back(-1);
                }
                else{
                    nsl.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        
        vector<ll> nsr;
        
        nsr.push_back(n);
        
        while(s.size()){
            s.pop();
        }
        
        s.push({arr[n-1],n-1});
        
        for(ll i = n - 2; i >= 0; i--){
            
            if(s.top().first < arr[i]){
                nsr.push_back(s.top().second);
            }
            else{
                
                while(!s.empty() && s.top().first >= arr[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    nsr.push_back(n);
                }
                else{
                    nsr.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        ll prod = INT_MIN;
        
        for(ll i = 0; i < n; i++){
            
            ll larea, rarea;
            
            larea = (i - nsl[i] - 1)*(arr[i]);
            rarea = (nsr[i] - i - 1)*(arr[i]);
            
            prod = max(prod,larea+rarea+arr[i]);
        }
        
        return prod;
    }
};

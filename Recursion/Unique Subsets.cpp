class Solution
{
    public:
    
    set<vector<int>> s;
    
    void solve(int ind,int n,vector<int> arr,vector<int> v){
        
        if(ind == n){
            s.insert(v);
            return;
        }
        
        solve(ind+1,n,arr,v);
        v.push_back(arr[ind]);
        solve(ind+1,n,arr,v);
        
        return;
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> p;
        vector<int> v;
        
        
        solve(0,n,arr,v);
        
        set<vector<int>> :: iterator it;
        
        for(it = s.begin(); it!=s.end(); it++){
            p.push_back(*it);
        }
        
        return p;
    }
};

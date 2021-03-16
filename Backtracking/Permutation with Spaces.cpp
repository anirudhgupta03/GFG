class Solution{
public:
    void solve(string &s, vector<string> &v, string S, int ind){
        
        if(ind == S.size()){
            v.push_back(s);
            return;
        }
        
        s.push_back(' ');
        s.push_back(S[ind]);
        solve(s,v,S,ind+1);
        s.pop_back();
        s.pop_back();
        s.push_back(S[ind]);
        solve(s,v,S,ind+1);
        s.pop_back();
    }
    vector<string> permutation(string S){
        
        vector<string> v;
        
        string s;
        
        s.push_back(S[0]);
        
        solve(s,v,S,1);
        
        return v;
    }
};

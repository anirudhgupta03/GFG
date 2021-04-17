//Using Backtracking
class Solution{
public:
    void solve(int ind, string &s, string S, vector<string> &res){
        
        if(ind == S.size()){
            res.push_back(s);
            return;
        }
        
        s.push_back(' ');
        s.push_back(S[ind]);
        solve(ind+1,s,S,res);
        s.pop_back();
        s.pop_back();
        s.push_back(S[ind]);
        solve(ind+1,s,S,res);
        s.pop_back();
    }
    vector<string> permutation(string S){
        
        string s;
        s.push_back(S[0]);
        
        vector<string> res;
        solve(1,s,S,res);
        
        return res;
    }
};

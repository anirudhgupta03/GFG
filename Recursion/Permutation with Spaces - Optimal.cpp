class Solution{
public:
    void solve(string S,string s,vector<string> &p){
        
        if(S == ""){
            p.push_back(s);
            return;
        }
        
        string op1 = s;
        string op2 = s;
        
        op1.push_back(' ');
        op1.push_back(S[0]);
        op2.push_back(S[0]);
        
        S.erase(S.begin());
        
        solve(S,op1,p);
        solve(S,op2,p);
        return;
    }
    vector<string> permutation(string S){
        
        int n = S.size();
        
        string op;
        op.push_back(S[0]);
        
        S.erase(S.begin());
        
        vector<string> p;
        string s;
        
        solve(S,op,p);
        return p;
    }
};

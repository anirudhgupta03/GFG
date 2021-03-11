class Solution{/698
public:
    void solve(int ind, int n, vector<string> &p, string s,string S){
        
        if(ind == n){
            p.push_back(s);
            return;
        }
        
        s.push_back(S[ind]);
        solve(ind+1,n,p,s,S);
        if(ind != n-1){
            s.push_back(' ');
            solve(ind+1,n,p,s,S);
        }
        return;
    }
    vector<string> permutation(string S){
        
        int n = S.size();
        vector<string> p;
        string s;
        
        solve(0,n,p,s,S);
        sort(p.begin(),p.end());
        return p;
    }
};

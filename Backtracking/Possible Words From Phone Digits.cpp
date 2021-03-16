class Solution{
    public:
    
    void solve(int ind, vector<string> &v, map<int,string> &m, string &s, int N, int a[])
    {
        if(ind == N){
            v.push_back(s);
            return;
        }
        
            for(int j = 0; j < m[a[ind]].size(); j++){
                
                string p = m[a[ind]];
                s.push_back(p[j]);
                solve(ind+1,v,m,s,N,a);
                s.pop_back();
            }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> v;
        string s;
        
        map<int,string> m;
        
        m[1] = "1";
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        solve(0,v,m,s,N,a);
        return v;
    }
};

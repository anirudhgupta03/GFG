class Solution
{
    public:
    
    void solve(int count1, int count2, string &s, vector<string> &v, int n){
        
        if(count1 == n && count2 == n){
            v.push_back(s);
            return;
        }
        
        if(count1 != n){
            s.push_back('(');
            solve(count1 + 1, count2,s,v,n);
            s.pop_back();
        }
        
        if(count1 != count2){
            s.push_back(')');
            solve(count1, count2 + 1,s,v,n);
            s.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> v;
        
        string s;
        
        solve(0,0,s,v,n);
        
        return v;
    }
};

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int c1, int c2, int n, vector<string> &res, string &temp){
        
        if(c1 == n && c2 == n){
            res.push_back(temp);
            return;
        }
        
        if(c1 != n){
            temp.push_back('(');
            solve(c1+1,c2,n,res,temp);
            temp.pop_back();
        }
        
        if(c2 < c1){
            temp.push_back(')');
            solve(c1,c2+1,n,res,temp);
            temp.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        string temp;
        int c1 = 0, c2 = 0;
        
        solve(c1,c2,n,res,temp);
        
        return res;
    }
};

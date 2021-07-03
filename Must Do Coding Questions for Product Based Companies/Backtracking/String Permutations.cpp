class Solution{
public:
    //Complete this function
    void solve(int ind, string &S, vector<string> &res){
        
        if(ind == S.size()){
            res.push_back(S);
        }
        
        for(int i = ind; i < S.size(); i++){
            swap(S[i],S[ind]);
            solve(ind + 1,S,res);
            swap(S[i],S[ind]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> res;
        
        solve(0,S,res);
        
        sort(res.begin(),res.end());
        
        return res;
    }
};

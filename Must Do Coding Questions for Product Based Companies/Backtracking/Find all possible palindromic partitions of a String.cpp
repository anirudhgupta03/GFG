class Solution {
  public:
    bool isPalindrome(string s){
        
        int l = 0, r = s.size() - 1;
        
        while(l < r){
            
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int ind, vector<string> &temp, vector<vector<string>> &res,string S){
        
        if(ind == S.size()){
            res.push_back(temp);
            return;
        }
        
        for(int i = ind; i < S.size(); i++){
            
            if(isPalindrome(S.substr(ind,i-ind+1))){
                temp.push_back(S.substr(ind,i-ind+1));
                solve(i+1,temp,res,S);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        
        vector<vector<string>> res;
        vector<string> temp;
        
        solve(0,temp,res,S);
        
        return res;
    }
};

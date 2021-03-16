class Solution {
  public:
    
    bool isPalindrome(string str, int l, int r){
        
        while(l < r){
            
            if(str[l] != str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(vector<vector<string>> &vec, vector<string> &v, string &S, int index){
        
        if(index == S.size()){
            vec.push_back(v);
            return;
        }
        
        for(int i = index; i < S.size(); i++){
            if(isPalindrome(S,index,i)){
                v.push_back(S.substr(index,i-index+1));
                solve(vec,v,S,i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> getGray(string S) {
        
        vector<vector<string>> vec;
        vector<string> v;
        string s;
        
        solve(vec,v,S,0);
        
        return vec;
    }
};

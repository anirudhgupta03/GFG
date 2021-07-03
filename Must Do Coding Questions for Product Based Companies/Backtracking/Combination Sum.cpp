class Solution 
{
    public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int ind, vector<int> &temp, set<vector<int>> &s, vector<int> &A, int B){
        
        if(B == 0){
            s.insert(temp);
            return;
        }
        if(B < 0 || ind == A.size()){
            return;
        }
        
        if(A[ind] <= B){
            temp.push_back(A[ind]);
            solve(ind,temp,s,A,B-A[ind]);
            temp.pop_back();
            solve(ind+1,temp,s,A,B);
        }
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        
        vector<int> C;
        
        set<int> s1;
        
        for(int i = 0; i < A.size(); i++){
            s1.insert(A[i]);
        }
        for(auto x: s1){
            C.push_back(x);
        }
        
        vector<vector<int>> res;
        
        vector<int> temp;
        
        set<vector<int>> s2;
        
        solve(0,temp,s2,C,B);
        
        for(auto x: s2){
            res.push_back(x);
        }
        return res;
    }
};

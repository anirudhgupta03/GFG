class Solution{
public:
    bool isSafe(int x, int y, vector<vector<int>> &temp, int n){
        for(int i = x; i >= 0; i--){
            if(temp[i][y]){
                return false;
            }
        }
        
        for(int i = x, j = y; i >=0 && j >= 0; i--,j--){
            if(temp[i][j]){
                return false;
            }
        }
        
        for(int i = x, j = y; i >= 0 && j < n; i--,j++){
            if(temp[i][j]){
                return false;
            }
        }
        return true;
    }
    void solve(int x, vector<vector<int>> &res, vector<vector<int>> &temp, vector<int> &v, int n){
        
        if(x == n){
            res.push_back(v);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isSafe(x,j,temp,n)){
                v.push_back(j+1);
                temp[x][j] = 1;
                solve(x+1,res,temp,v,n);
                v.pop_back();
                temp[x][j] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> res;
        vector<vector<int>> temp(n,vector<int>(n,0));
        
        vector<int> v;
        
        solve(0,res,temp,v,n);
        
        return res;
    }
};

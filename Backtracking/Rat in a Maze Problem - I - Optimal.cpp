class Solution{
    public:
    
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    char dir[4] = {'D','L','R','U'};
    
    bool isValid(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> &vis){
        
        if(x < 0 || x >= n || y < 0 || y >= n){
            return false;
        }
        
        if(m[x][y] == 0 || vis[x][y] == 1){
            return false;
        }
        return true;
    }
    void solve(int x, int y, vector<string> &res, string &path,vector<vector<int>> &m, int n, vector<vector<int>> &vis ){
        
        if(x == n - 1 && y == n - 1){
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < 4; i++){
            
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(isValid(newx,newy,m,n,vis)){
                
                path.push_back(dir[i]);
                vis[newx][newy] = 1;
                solve(newx,newy,res,path,m,n,vis);
                path.pop_back();
                vis[newx][newy] = 0;
              
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> res;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            res.push_back("-1");
            return res;
        }
        
        string path;
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        vis[0][0] = 1;
        solve(0,0,res,path,m,n,vis);
        
        return res;
    }
};

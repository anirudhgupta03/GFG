class Solution{
    public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char dir[4] = {'U','D','L','R'};
    void solve(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> &vis, vector<string> &res, string &temp){
        
        if(x == n - 1 && y == n - 1){
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < 4; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < n && yo >= 0 && yo < n && vis[xo][yo] == 0 && m[xo][yo] == 1) {
                temp.push_back(dir[i]);
                vis[xo][yo] = 1;
                solve(xo,yo,m,n,vis,res,temp);
                vis[xo][yo] = 0;
                temp.pop_back();
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> res;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return res;
        }
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        string temp;
        
        vis[0][0] = 1;
        
        solve(0,0,m,n,vis,res,temp);
        
        sort(res.begin(),res.end());
        
        return res;
    }
};

class Solution{
public:
    int dx[8] = {-1,1,0,0,1,1,-1,-1};
    int dy[8] = {0,0,-1,1,1,-1,1,-1};
    
    bool isValid(int x, int y, int n, int m,vector<vector<int>> &vis, vector<vector<char>> &grid){
        
        if(x < 0 || x >= n || y < 0 || y >= m){
            return false;
        }
        
        if(vis[x][y] == true || grid[x][y] == '0'){
            return false;
        }
        return true;
    }
    void dfs(int x, int y,int n, int m,vector<vector<int>> &vis,vector<vector<char>> &grid){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 8; i++){
            
            if(isValid(x + dx[i], y + dy[i], n, m, vis, grid)){
                
                dfs(x + dx[i], y + dy[i], n, m, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        int cc_count = 0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(vis[i][j] == 0){
                    
                    if(grid[i][j] == '1'){
                        dfs(i,j,n,m,vis,grid);
                        cc_count++;
                    }
                    
                }
            }
        }
        return cc_count;
    }
};

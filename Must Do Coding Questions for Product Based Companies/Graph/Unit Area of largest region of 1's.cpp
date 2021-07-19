class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dx[8] = {0,0,-1,1,-1,1,-1,1};
    int dy[8] = {-1,1,0,0,-1,1,1,-1};
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid, int &count){
        
        vis[x][y] = 1;
        count++;
        
        for(int i = 0; i < 8; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && xo < grid.size() && yo >= 0 && yo < grid[0].size()){
                if(grid[xo][yo] == 1 && vis[xo][yo] == 0){
                    dfs(xo,yo,vis,grid,count);
                }
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int maxArea = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int count = 0;
                    dfs(i,j,vis,grid,count);
                    maxArea = max(maxArea,count);
                }
            }
        }
        
        return maxArea;
    }
};

//Method - 1
class Solution {
  public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char dc[4] = {'U','D','L','R'};
    void dfs(int srcx, int srcy, int x, int y, vector<vector<int>>&grid, vector<vector<int>> &vis, string &island){
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()){
                if(vis[nx][ny] == 0 && grid[nx][ny] == 1){
                    island.push_back(dc[i]);
                    dfs(srcx, srcy, nx, ny, grid, vis, island);
                }
            }
        }
        island.push_back('B');
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<string> islands;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    string island;
                    dfs(i, j, i, j, grid, vis, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
};

//Method - 2
// User function Template for C++

class Solution {
  public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int srcx, int srcy, int x, int y, vector<vector<int>>&grid, vector<vector<int>> &vis, vector<pair<int,int>> &island){
        vis[x][y] = 1;
        island.push_back({x - srcx, y - srcy});
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()){
                if(vis[nx][ny] == 0 && grid[nx][ny] == 1){
                    dfs(srcx, srcy, nx, ny, grid, vis, island);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> islands;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> island;
                    dfs(i, j, i, j, grid, vis, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
};

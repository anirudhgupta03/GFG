class Solution{
public:
  
    string dir[8] = {"TL", "T", "TR", "L", "R", "BL", "B", "BR"};
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    
    bool solve(int ind, int x, int y, vector<vector<char>> &grid, vector<vector<int>> &vis, string word, string direction){
        
        if(ind == word.size()){
            return true;
        }
        
        for(int i = 0; i < 8; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size()){
                if(vis[xo][yo] == 0 && grid[xo][yo] == word[ind]){
                    
                    if(direction == "" || dir[i] == direction){
                        vis[xo][yo] = 1;
                        bool flag = solve(ind + 1, xo, yo, grid, vis, word, dir[i]);
                        if(flag){
                            return true;
                        }
                        vis[xo][yo] = 0;
                    }
                }
            }
        }
        return false;
    }
	vector<vector<int>> searchWord(vector<vector<char>>grid, string word){
	    
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<int>> path;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            
	            if(grid[i][j] == word[0]){
	                
	                vector<vector<int>> vis(n, vector<int>(m,0));
	                vis[i][j] = 1;
	                string direction = "";
	                bool flag = solve(1, i, j, grid, vis, word, direction);
	                
	                if(flag){
	                    path.push_back({i,j});
	                }
	            }
	        }
	    }
	    sort(path.begin(),path.end());
	    return path;
	}
};

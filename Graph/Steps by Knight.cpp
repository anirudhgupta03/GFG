class Solution{
public:
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    bool isValid(int x, int y, vector<vector<int>> &vis, int N){
        
        if(x < 0 || x >= N || y < 0 || y >= N){
            return false;
        }
        
        if(vis[x][y] == 1){
            return false;
        }
        return true;
    }
    void bfs(int sx, int sy, vector<vector<int>> &vis, vector<vector<int>> &dist, int N){
        
        vis[sx][sy] = 1;
        dist[sx][sy] = 0;
        
        queue<pair<int,int>> q;
        q.push({sx,sy});
        
        while(!q.empty()){
            
            int currx = q.front().first, curry = q.front().second;
            q.pop();
            
            for(int i = 0; i < 8; i++){
                
                int newx = currx + dx[i], newy = curry + dy[i];
                
                if(isValid(newx, newy, vis, N)){
                    vis[newx][newy] = 1;
                    dist[newx][newy] = dist[currx][curry] + 1;
                    q.push({newx, newy});
                }
            }
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    
	    int sx = KnightPos[0] - 1, sy = KnightPos[1] - 1;
	    int ex = TargetPos[0] - 1, ey = TargetPos[1] - 1;
	    
	    vector<vector<int>> vis(N,vector<int>(N,0));
	    vector<vector<int>> dist(N,vector<int>(N));
	    
	    bfs(sx, sy, vis, dist, N);
	    
	    return dist[ex][ey];
	}
};

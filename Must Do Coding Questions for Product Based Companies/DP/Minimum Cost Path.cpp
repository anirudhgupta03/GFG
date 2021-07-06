class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	#define pipii pair<int,pair<int,int>> 
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        
        int n = grid.size();
        
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            
            int currd = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if(vis[x][y]) continue;
            
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                
                if(xo >= 0 && xo < n && yo >= 0 && yo < n && vis[xo][yo] == 0){
                    
                    int d = grid[x][y];
                    
                    if(currd + d < cost[xo][yo]){
                        cost[xo][yo] = currd + d;
                        pq.push({cost[xo][yo],{xo,yo}});
                    }
                }
            }
        }
        
        return cost[n-1][n-1] + grid[n-1][n-1];
    }
};

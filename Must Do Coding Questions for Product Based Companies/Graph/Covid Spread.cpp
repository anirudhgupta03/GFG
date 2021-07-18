class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int helpaterp(vector<vector<int>> hospital)
    {
        int r = hospital.size(), c = hospital[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<vector<int>> vis(r,vector<int>(c,0));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(hospital[i][j] == 2){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int minTime = 0;
        
        while(!q.empty()){
            
            int t = q.front().first, x = q.front().second.first, y = q.front().second.second;
            minTime = max(minTime,t);
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && xo < r && yo >= 0 && yo < c && vis[xo][yo] == 0 && hospital[xo][yo] == 1){
                    q.push({t+1,{xo,yo}});
                    vis[xo][yo] = 1;
                }
            }
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(hospital[i][j] == 1 && vis[i][j] == 0){
                    return -1;
                }
            }
        }
        
        return minTime;
    }
};

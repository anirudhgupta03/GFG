class Solution{
    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        queue<pair<int,int>> q;
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
         
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(matrix[i][j] == 'B'){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
                if(matrix[i][j] == 'W'){
                    dist[i][j] = -1;
                }
            }
        }
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        int level = 1;
        while(!q.empty()){
            
            int x = q.front().first, y = q.front().second;
            q.pop();
                
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < M && yo < N){
                    if(matrix[xo][yo] == 'O'){
                        if(dist[xo][yo] > dist[x][y] + 1){
                            dist[xo][yo] = dist[x][y] + 1;
                            q.push({xo, yo});
                        }
                    }
                }
            }
        }
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(matrix[i][j] == 'O' && dist[i][j] == INT_MAX){
                    dist[i][j] = -1;
                }
            }
        }
        return dist;
    } 
};

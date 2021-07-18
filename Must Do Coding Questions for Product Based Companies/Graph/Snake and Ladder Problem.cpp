class Solution{
public:
    int minThrow(int N, int arr[]){
        
        vector<int> game(30);
        
        for(int i = 0; i < 30; i++) game[i] = i;
        
        for(int i = 0; i < 2*N; i += 2){
            int s = arr[i], e = arr[i+1];
            game[s-1] = e - 1;
        }
        
        queue<int> q;
        q.push(0);
        
        vector<int> vis(30,0), dist(30,0);
        
        vis[0] = 1;
        dist[0] = 0;
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            for(int i = 1; i <= 6; i++){
                int io = curr + i;
                if(io < 30){
                    if(vis[game[io]] == 0){
                        dist[game[io]] = dist[curr] + 1;
                        vis[game[io]] = 1;
                        q.push(game[io]);
                    }
                }
            }
        }
        return dist[29];
    }
};

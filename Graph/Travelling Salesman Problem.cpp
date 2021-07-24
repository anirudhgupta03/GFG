class Solution {
public:

void solve(int city, vector<int> &vis, vector<vector<int>> &cost, int &minCost, int currCost){
    
    bool flag = false;
    
    for(int i = 0; i < cost.size(); i++){
        
        if(vis[i] == 0){
            flag = true;
            vis[i] = 1;
            solve(i,vis,cost,minCost,currCost + cost[city][i]);
            vis[i] = 0;
        }
    }
    
    if(!flag){
        minCost = min(minCost, currCost + cost[city][0]);
    }
}
int total_cost(vector<vector<int>>cost){

    int cities = cost.size();
    
    vector<int> vis(cities,0);
    
    int minCost = INT_MAX, currCost = 0;
    
    vis[0] = 1;
    
    solve(0,vis,cost,minCost,currCost);
    
    return minCost;
}
};

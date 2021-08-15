//https://www.codingninjas.com/codestudio/problems/is-graph-tree_1115787?leftPanelTab=0
void dfs(int node, vector<int> al[], vector<int> &vis){
    
    vis[node] = 1;
    for(int i = 0; i < al[node].size(); i++){
        int child = al[node][i];
        if(vis[child] == 0){
            dfs(child, al, vis);
        }
    }
}
bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
	  int m = edgeList.size();
    
    if(m != n - 1){
        return false;
    }
    
    int cc_count = 0;
    vector<int> al[n];
    
    for(int i = 0; i < edgeList.size(); i++){
        int a = edgeList[i][0], b = edgeList[i][1];
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    vector<int> vis(n,0);
    
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            dfs(i, al, vis);
            cc_count++;
        }
    }
    
    if(cc_count > 1){
        return false;
    }
    return true;
}

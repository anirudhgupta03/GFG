//Ref: https://www.youtube.com/watch?v=wuVwUK25Rfc
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
    
    for(int k = 0; k < n; k++){
        if(k != node && graph[k][node] == 1 && color[k] == col){
            return false;
        }
    }
    return true;
}
bool solve(int node, int color[], int m, int V, bool graph[101][101]){
    
    if(node == V){
        return true;
    }
    
    for(int i = 1; i <= m; i++){
        if(isSafe(node, color, graph, V, i)){
            color[node] = i;
            if(solve(node+1, color, m, V, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};
    if(solve(0,color,m,V,graph)) return true;
    return false;
}

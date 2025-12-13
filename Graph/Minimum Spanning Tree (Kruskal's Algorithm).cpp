//DSU (By Rank)
class Solution {
  public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[2] < v2[2];
    }
    int findPar(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findPar(par[node], par);
    }
    void merge(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> treeEdges = edges;
        sort(treeEdges.begin(), treeEdges.end(), cmp);
        vector<int> par(V, -1);
        for(int i = 0; i < V; i++){
            par[i] = i;
        }
        vector<int> rank(V, 0);
        int mstWeight = 0;
        for(auto &edge: treeEdges){
            int u = edge[0], v = edge[1], w = edge[2];
            int parU = findPar(u, par);
            int parV = findPar(v, par);
            if(parU != parV){
                mstWeight += w;
                if(rank[parU] >= rank[parV]){
                    rank[parU] = max(rank[parU], rank[parV] + 1);
                    merge(parU, parV, par);
                }
                else{
                    merge(parV, parU, par);
                }
            }
        }
        return mstWeight;
    }
};

//DSU (By Size)
class Solution {
  public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[2] < v2[2];
    }
    int findPar(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findPar(par[node], par);
    }
    void merge(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> treeEdges = edges;
        sort(treeEdges.begin(), treeEdges.end(), cmp);
        vector<int> par(V, -1);
        for(int i = 0; i < V; i++){
            par[i] = i;
        }
        vector<int> size(V, 1);
        int mstWeight = 0;
        for(auto &edge: treeEdges){
            int u = edge[0], v = edge[1], w = edge[2];
            int parU = findPar(u, par);
            int parV = findPar(v, par);
            if(parU != parV){
                mstWeight += w;
                if(size[parU] >= size[parV]){
                    size[parU] += size[parV];
                    merge(parU, parV, par);
                }
                else{
                    size[parV] += size[parU];
                    merge(parV, parU, par);
                }
            }
        }
        return mstWeight;
    }
};

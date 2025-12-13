// User function Template for C++
class Solution {
  public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int findPar(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findPar(par[node], par);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> par(n*m,-1);
        for(int i = 0; i < n*m; i++){
            par[i] = i;
        }
        vector<vector<int>> islands(n, vector<int>(m, 0));
        vector<int> res;
        int count = 0;
        for(auto &op: operators){
            int x = op[0], y = op[1];
            if(islands[x][y] == 1){
                res.push_back(count);
                continue;
            }
            islands[x][y] = 1;
            int pari = m*x + y;
            count++;
            for(int i = 0; i < 4; i++){
                int px = x + dx[i], py = y + dy[i];
                if(px >= 0 && py >= 0 && px < n && py < m && islands[px][py]){
                    int parn = findPar(m*px + py, par);
                    pari = findPar(pari, par);           
                    if(parn != pari){
                        par[pari] = parn;
                        count--;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

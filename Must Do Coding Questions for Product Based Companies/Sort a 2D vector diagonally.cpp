class Solution{
public:
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        
        for(int i = 1; i < n; i++){
            
            int xl = i, yl = 0;
            
            vector<int> temp;
            
            while(xl <= n - 1 && yl <= m - 1){
                temp.push_back(matrix[xl][yl]);
                xl++;
                yl++;
            }
            
            sort(temp.begin(),temp.end());
            
            xl = i, yl = 0;
            
            int k = 0;
            
            while(xl <= n - 1 && yl <= m - 1){
                matrix[xl][yl] = temp[k];
                xl++;
                yl++;
                k++;
            }
        }
        
        for(int j = 1;  j < m; j++){
            
            int xl = 0, yl = j;
            
            vector<int> temp;
            
            while(xl <= n - 1 && yl <= m - 1){
                temp.push_back(matrix[xl][yl]);
                xl++;
                yl++;
            }
            
            sort(temp.begin(),temp.end(),greater<int>());
            
            xl = 0, yl = j;
            
            int k = 0;
            
            while(xl <= n - 1 && yl <= m - 1){
                matrix[xl][yl] = temp[k];
                xl++;
                yl++;
                k++;
            }
        }
    }
};

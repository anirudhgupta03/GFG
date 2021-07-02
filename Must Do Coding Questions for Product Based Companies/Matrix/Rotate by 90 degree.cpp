void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    for(int j = 0; j < n; j++){
        
        int l = 0, r = n - 1;
        while(l < r){
            swap(matrix[l][j],matrix[r][j]);
            l++;
            r--;
        }
    }
}

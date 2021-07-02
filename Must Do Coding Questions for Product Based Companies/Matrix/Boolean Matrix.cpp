class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
       int r = matrix.size(), c = matrix[0].size();
       
       vector<int> row(r,0), col(c,0);
       
       for(int i = 0; i < r; i++){
           for(int j = 0; j < c; j++){
               
               if(matrix[i][j] == 1){
                   row[i] = 1;
                   col[j] = 1;
               }
           }
       }
       
       for(int i = 0; i < r; i++){
           for(int j = 0; j < c; j++){
               if(row[i] == 1 || col[j] == 1){
                   matrix[i][j] = 1;
               }
           }
       }
    }
};

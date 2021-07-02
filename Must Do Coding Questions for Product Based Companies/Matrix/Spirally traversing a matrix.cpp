class Solution{
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left = 0, top = 0, right = c - 1, bottom = r - 1;
        
        vector<int> res;
        
        int dir = 1, i = 0, j = 0;
        
        while(res.size() != r*c){
            
            if(dir == 1){
                
                while(j <= right){
                    res.push_back(matrix[top][j]);
                    j++;
                }
                
                j--;
                top++;
                i++;
                
                while(i <= bottom){
                    res.push_back(matrix[i][right]);
                    i++;
                }
                
                i--;
                right--;
                j--;
                
                dir = 0;
            }
            else{
                
                while(j >= left){
                    res.push_back(matrix[bottom][j]);
                    j--;
                }
                
                j++;
                bottom--;
                i--;
                
                while(i >= top){
                    res.push_back(matrix[i][left]);
                    i--;
                }
                
                i++;
                left++;
                j++;
                
                dir = 1;
            }
        }
        
        return res;
    }
};

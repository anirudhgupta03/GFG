//Method - 1
//Time Complexity - O(NlogM)
//Space Complexity - O(1)
class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        for(int i = 0; i < n; i++){
            
            int lo = 0, hi = m - 1;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(matrix[i][mid] > x){
                    hi = mid - 1;
                }
                else if(matrix[i][mid] == x){
                    return 1;
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        return 0;
    }
};

//Method - 2
//Optimal
//Time Complexity - O(N+M)
//Space Complexity - O(1)
class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        int i = 0, j = m - 1;
        
        while(i >= 0 && i < n && j >= 0 && j < m){
            
            if(matrix[i][j] > x){
                j--;
            }
            else if(matrix[i][j] < x){
                i++;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};

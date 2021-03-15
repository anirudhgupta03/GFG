class Solution{
    public:

    bool isSafe(int row, int col, vector<vector<int>> &m, int n, vector<vector<bool>> &visited){
        
        if(row == n || row == -1 || col == -1 || col == n || visited[row][col] || m[row][col] == 0){
            return false;
        }
        
        return true;
    }
    void maze(int row,int col,vector<string> &v, string &s, vector<vector<int>> &m, vector<vector<bool>> &visited, int n){
        
        if(row == n - 1 && col == n - 1){
            v.push_back(s);
            return;
        }
        
        visited[row][col] = true;                 //Mark the cell as visited
        
        if(isSafe(row + 1, col, m, n, visited)){  //Check if down move is valid
            s.push_back('D');
            maze(row + 1, col, v, s, m ,visited, n);
            s.pop_back();
        }
        
        if(isSafe(row, col - 1, m, n, visited)){  //Check if left move is valid
            s.push_back('L');
            maze(row, col - 1, v, s, m ,visited, n);
            s.pop_back();
        }
        
        if(isSafe(row, col + 1, m, n, visited)){  //Check if right move is valid
            s.push_back('R');
            maze(row, col + 1, v, s, m ,visited, n);
            s.pop_back();
        }
        
        if(isSafe(row - 1, col, m, n, visited)){  //Check if up move is valid
            s.push_back('U');
            maze(row - 1, col, v, s, m ,visited, n);
            s.pop_back();
        }
        
        visited[row][col] = false;                //Mark the cell as unvisited
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> v;
        if( m[0][0] == 0 || m[n-1][n-1] == 0){   //If starting position or last position is blocked then there is no path possible
            return v;
        }
        
        string s;
        
        vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
        
        maze(0,0,v,s,m,visited,n);
        
        return v;
    }
};

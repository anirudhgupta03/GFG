class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool isValid(int x, int y, int grid[N][N], int n){
        
        for(int j = 0; j < 9; j++){
            if(grid[x][j] == n){
                return false;
            }
        }
        for(int i = 0; i < 9; i++){
            if(grid[i][y] == n){
                return false;
            }
        }
        for(int i = (x/3)*3; i < (x/3)*3 + 3; i++){
            for(int j = (y/3)*3; j < (y/3)*3 + 3; j++){
                if(grid[i][j] == n){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(int x, int y, int grid[N][N], vector<vector<int>> &ansgrid, bool &flag){
        
        if(y == N){
            x++;
            y = 0;
        }
        
        if(x == N){
            //cout << "HI" << endl;
            flag = true;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    ansgrid[i][j] = grid[i][j];
                }
            }
            return;
        }
        
        if(grid[x][y] == 0){
            for(int i = 1; i <= 9; i++){
                if(isValid(x,y,grid,i)){
                    grid[x][y] = i;
                    solve(x, y + 1, grid, ansgrid, flag);
                    grid[x][y] = 0;
                }
            }    
        }
        else{
            solve(x, y + 1, grid, ansgrid, flag);
        }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        bool flag = false;
        vector<vector<int>> ansgrid(N, vector<int>(N));
        
        solve(0, 0, grid, ansgrid, flag);
        // printGrid(ansgrid);
        if(flag){
            //grid = ansgrid;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    grid[i][j] = ansgrid[i][j];
                }
            }
        }
        //cout << flag << endl;
        return flag;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << grid[i][j] << " ";
            }
            //cout << endl;
        }
    }
};

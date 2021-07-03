//Method - 1
//TLE
class Solution{
public:
    int dx[3] = {1,1,1};
    int dy[3] = {0,-1,1};
    
    int solve(int x, int y, vector<vector<int>> Matrix, int N, vector<vector<int>> &dp){
        
        if(x == N - 1){
            return Matrix[x][y];
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int maxSum = 0;
        for(int i = 0; i < 3; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < N && yo >= 0 && yo < N){
                maxSum = max(maxSum,solve(xo,yo,Matrix,N,dp) + Matrix[x][y]);
            }
        }
        return dp[x][y] = maxSum;
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxPathSum = 0;
        
        vector<vector<int>> dp(N,vector<int>(N,-1));
        
        for(int j = 0; j < N; j++){
            maxPathSum = max(maxPathSum,solve(0,j,Matrix,N,dp));
        }
        
        return maxPathSum;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=OCz6rm9Nh1o
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        for(int i = 1; i < N; i++){
            
            for(int j = 0; j < N; j++){
                
                if(j == 0){
                    Matrix[i][j] += max(Matrix[i-1][j], Matrix[i-1][j+1]) ;
                }
                else if(j == N - 1){
                    Matrix[i][j] += max(Matrix[i-1][j], Matrix[i-1][j-1]);
                }
                else{
                    Matrix[i][j] += max({Matrix[i-1][j], Matrix[i-1][j-1], Matrix[i-1][j+1]});
                }
            }
        }
        
        int maxPathSum = 0;
        
        for(int j = 0; j < N; j++){
            maxPathSum = max(maxPathSum, Matrix[N-1][j]);
        }
        return maxPathSum;
    }
};

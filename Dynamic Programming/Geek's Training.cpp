//Recursion + Memoization
class Solution {
  public:
    int findMaximumPoints(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &dp){
        
        if(row == arr.size()) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        if(col == 0){
            return dp[row][col] = arr[row][col] + max(findMaximumPoints(row + 1, 1, arr, dp), findMaximumPoints(row + 1, 2, arr, dp));
        }
        else if(col == 1){
            return dp[row][col] = arr[row][col] + max(findMaximumPoints(row + 1, 0, arr, dp), findMaximumPoints(row + 1, 2, arr, dp));
        }
        return dp[row][col] = arr[row][col] + max(findMaximumPoints(row + 1, 0, arr, dp), findMaximumPoints(row + 1, 1, arr, dp));
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return max({findMaximumPoints(0, 0, arr, dp), findMaximumPoints(0, 1, arr, dp), findMaximumPoints(0, 2, arr, dp)});
    }
};

//Tabulation
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        
        vector<vector<int>> meritPoints(n, vector<int>(3));
        meritPoints[0][0] = arr[0][0];
        meritPoints[0][1] = arr[0][1];
        meritPoints[0][2] = arr[0][2];
        
        for(int i = 1; i < n; i++){
            meritPoints[i][0] = max(meritPoints[i-1][1], meritPoints[i-1][2]) + arr[i][0];
            meritPoints[i][1] = max(meritPoints[i-1][0], meritPoints[i-1][2]) + arr[i][1];
            meritPoints[i][2] = max(meritPoints[i-1][0], meritPoints[i-1][1]) + arr[i][2];
        }
        
        return max({meritPoints[n - 1][0], meritPoints[n - 1][1], meritPoints[n - 1][2]});
    }
};

//Tabulation + Space Optimization
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        
        vector<int> meritPoints(3, 0);
        meritPoints[0] = arr[0][0];
        meritPoints[1] = arr[0][1];
        meritPoints[2] = arr[0][2];
        
        for(int i = 1; i < n; i++){
            vector<int> points(3, 0);
            points[0] = max(meritPoints[1], meritPoints[2]) + arr[i][0];
            points[1] = max(meritPoints[0], meritPoints[2]) + arr[i][1];
            points[2] = max(meritPoints[0], meritPoints[1]) + arr[i][2];
            meritPoints = points;
        }
        
        return max({meritPoints[0], meritPoints[1], meritPoints[2]});
    }
};

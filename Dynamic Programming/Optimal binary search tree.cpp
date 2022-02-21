//Ref: https://www.youtube.com/watch?v=HnslzEs8dbY
//Expert Question
class Solution{
    public:
    int optimalSearchTree(int keys[], int frequency[], int n)
    {
        int dp[n][n];
        
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){
                if(g == 0){
                    dp[i][j] = frequency[i];
                }
                else if(g == 1){
                    int f1 = frequency[i];
                    int f2 = frequency[j];
                    dp[i][j] = min(f1 + 2*f2, 2*f1 + f2);
                }
                else{
                    int minSum = INT_MAX, sum = 0;
                    for(int k = i; k <= j; k++){
                        sum += frequency[k];
                    }
                    for(int k = i; k <= j; k++){
                        int left = k == i ? 0 : dp[i][k - 1];
                        int right = k == j ? 0 : dp[k + 1][j];
                        
                        if(left + right + sum < minSum){
                            minSum = left + right + sum;
                        }
                    }
                    dp[i][j] = minSum;
                }
            }
        }
        return dp[0][n - 1];
    }
};

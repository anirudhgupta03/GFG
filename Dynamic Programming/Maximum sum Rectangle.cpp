//Ref: https://www.youtube.com/watch?v=kKEX4P53MyY
class Solution {
  public:
    int kadane(vector<int> temp){
        
        int currSum = 0, maxSum = INT_MIN;
        
        for(int i = 0; i < temp.size(); i++){
            
            currSum += temp[i];
            
            maxSum = max(maxSum, currSum);
            
            if(currSum < 0){
                currSum = 0;
            }
        }
        
        return maxSum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        
        int maxSum = INT_MIN;
        
        for(int i = 0; i < R; i++){
            
            vector<int> temp(C,0);
            
            for(int j = i; j < R; j++){
                for(int k = 0; k < C; k++){
                    temp[k] += M[j][k];
                }
                
                maxSum = max(maxSum, kadane(temp));
            }
        }
        
        return maxSum;
    }
};

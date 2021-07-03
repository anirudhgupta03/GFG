//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(N)
class Solution{
  public:
    int minJumps(int arr[], int n){
        
        int dp[n] = {0};
        
        int maxCover = 0;
        
        if(arr[0] == -1){
            return 0;
        }
        
        dp[0] = 0;
        
        for(int i = 0; i < n - 1; i++){
            
            if(i == 0 || dp[i]){
                
                if(arr[i] == 0){
                    continue;
                }
                for(int j = maxCover + 1; j <= i + arr[i]; j++){
                    if(j < n){
                        dp[j] = dp[i] + 1;
                    }
                    else{
                        break;
                    }
                }
                maxCover = max(maxCover, i + arr[i]);
            }
            else{
                return -1;
            }
        }
        
        
        if(!dp[n-1]){
            return -1;
        }
        return dp[n-1];
    }
};

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
class Solution{
  public:
    int minJumps(int arr[], int n){
        
        int maxR = arr[0];
        int step = arr[0];
        int jump = 1;
        if(n == 1){
            return 0;
        }
        else if(arr[0] == 0){
            return -1;
        }
        else{
            for(int i = 1; i < n; i++){
                if(i == n - 1){
                    return jump;
                }
                maxR = max(maxR,i+arr[i]);
                step--;
                if(step == 0){
                    jump++;
                    if(i >= maxR){
                        return -1;
                    }
                    step = maxR - i;
                }
            }
        }
    }
};

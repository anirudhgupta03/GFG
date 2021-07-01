//Ref: youtube.com/watch?v=Q1TYVUEr-wY
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        int arrSum = 0;
        bool flag = false;
        int ans = INT_MIN;
        
        for(int i = 0; i < num; i++){
            if(arr[i] >= 0){
                flag = true;
            }
            else{
                ans = max(ans,arr[i]);
            }
        }
        
        if(flag == false){            //If all the elements are negative then return maximum among them
            return ans;
        }
        
        int maxSum1 = INT_MIN, currSum = 0;
        
        for(int i = 0; i < num; i++){
            currSum += arr[i];
            maxSum1 = max(maxSum1,currSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        
        for(int i = 0; i < num; i++){
            arr[i] = -1*arr[i];
            arrSum += arr[i];
        }
    
        int maxSum2 = INT_MIN;
        currSum = 0;
        
        for(int i = 0; i < num; i++){
            currSum += arr[i];
            maxSum2 = max(maxSum2, currSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return max(maxSum2 - arrSum,maxSum1);
    }
};

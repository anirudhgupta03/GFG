//Ref: https://www.youtube.com/watch?v=B01g0rGL9bA
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr,arr+N);
        
        int maxSum = 0;
        
        int i = N - 1;
        
        while(i > 0){
            
            if(arr[i] - arr[i-1] < K){
                maxSum += arr[i] + arr[i-1];
                i -= 2;
            }
            else{
                i--;
            }
        }
        
        return maxSum;
    }
};

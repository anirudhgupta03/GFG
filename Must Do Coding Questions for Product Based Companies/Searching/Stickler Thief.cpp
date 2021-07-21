class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1){
            return arr[0];
        }
        int max1 = arr[0];
        int max2 = max(arr[0],arr[1]);
        
        for(int i = 2; i < n; i++){
            
            if(i % 2 == 0){
                max1 += arr[i];
                max1 = max(max2,max1);
            }
            else{
                max2 += arr[i];
                max2 = max(max2,max1);
            }
        }
        
        return max(max1,max2);
    }
};

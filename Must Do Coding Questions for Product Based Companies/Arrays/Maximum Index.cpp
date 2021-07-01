class Solution{
    public:
        
    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        int right[n];
        
        right[n-1] = arr[n-1];
        
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(arr[i],right[i+1]);
        }
        int ans = 0, j = 0;
        
        for(int i = 0; i < n; i++){
            
            while(j < n && arr[i] <= right[j]){
                j++;
            }
            ans = max(ans,j-i-1);
            if(j == n)
            break;
        }
        return ans;
    }
};

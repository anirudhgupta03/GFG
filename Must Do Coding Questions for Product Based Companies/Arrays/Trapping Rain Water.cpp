class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        
        int left[n], right[n];
        
        left[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1],arr[i]);
        }
        
        right[n-1] = arr[n-1];
        
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(right[i+1],arr[i]);
        }
        
        int waterTrap = 0;
        
        for(int i = 1; i <= n - 2; i++){
            
            if(left[i-1] > arr[i] && arr[i] < right[i+1]){
                waterTrap += min(left[i-1],right[i+1]) - arr[i];
            }
        }
        
        return waterTrap;
    }
};

//Ref: https://www.youtube.com/watch?v=uUeZPQG-bPQ
int minSwap(int *arr, int n, int k) {
    
    int good = 0, bad = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] <= k){
            good++;
        }
    }
    
    for(int i = 0; i < good; i++){
        if(arr[i] > k){
            bad++;
        }
    }
    
    int l = 0, r = good-1;
    int ans = 1e9;
    
    while(r < n){
        
        ans = min(ans,bad);
        
        r++;
        if(arr[r] > k){
            bad++;
        }
        if(arr[l] > k){
            bad--;
        }
        l++;
    }
    
    return ans;
}

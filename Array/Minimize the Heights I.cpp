//https://www.youtube.com/watch?v=tSLiZAQG9NM
class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr,arr+n);
        
        int ans = arr[n-1] - arr[0];
        
        int mx, mn;
        
        for(int i = 0; i < n; i++){
            mx = max(arr[n-1]-k, arr[i-1] + k);
            mn = min(arr[0] + k, arr[i] - k);
            ans = min(ans, mx - mn);
        }
        
        return ans;
    }
}

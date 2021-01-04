class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr,arr+n);
        
        int ans,big,small;
        
        ans=arr[n-1]-arr[0];
        
        int mx,mn;
        for(int i=0;i<n;i++){
            
            if(arr[i]>=k)  // since height of tower can't be -ve so taking only +ve heights
            {
                mn = min(arr[0]+k, arr[i]-k); //taking the minimum height in mn
                mx = max(arr[n-1]-k, arr[i-1]+k); //taking the maximum height in mx
                ans = min(ans, mx-mn); //taking the minimum value of difference b/w the maximum height and minimum height
            }
        }
        return ans;
    }
};

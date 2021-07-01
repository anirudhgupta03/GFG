//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int K) {
    
    int n = arr.size();
    
    int lo = 0, hi = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        int prev = (mid+n-1)%n, next = (mid+1)%n;
        
        if(arr[mid] == K){
            return mid;
        }
        else if(arr[mid] <= arr[hi]){
            
            if(K >= arr[mid] && K <= arr[hi]){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        else{
            
            if(K >= arr[lo] && K <= arr[mid]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
    }
    return -1;
}

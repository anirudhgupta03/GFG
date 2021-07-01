double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
{
    int m = arr1.size(), n = arr2.size();
    
    if(m > n){
        swap(arr1,arr2);
        swap(m,n);
    }
    
    int k = (m+n+1)/2;
    
    int lo = 0, hi = m;
    
    while(lo <= hi){
        
        int cut1 = (lo + hi)/2;
        int cut2 = k - cut1;
        
        int l1,l2,r1,r2;
        
        if(cut1 == 0) l1 = INT_MIN;
        else          l1 = arr1[cut1 - 1];
        
        if(cut2 == 0) l2 = INT_MIN;
        else          l2 = arr2[cut2 - 1];
        
        if(cut1 == m) r1 = INT_MAX;
        else          r1 = arr1[cut1];
        
        if(cut2 == n) r2 = INT_MAX;
        else          r2 = arr2[cut2];
        
        if(l1 <= r2 && l2 <= r1){
            if((m+n) % 2 == 0){
                int e1 = max(l1,l2);
                int e2 = min(r1,r2);
                
                return (double)(e1+e2)/2;
            }
            else{
                return max(l1,l2);
            }
        }
        else if(l1 > r2){
            hi = cut1 - 1;
        }
        else{
            lo = cut1 + 1;
        }
    }
}

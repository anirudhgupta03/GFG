class Solution{  
  public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m){
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int lo = max(0,k-m), hi = min(k,n);
        
        while(lo <= hi){
            
            int cut1 = (lo + hi)/2;
            int cut2 = k - cut1;
            
            int l1, l2, r1, r2;
            
            if(cut1 == 0) l1 = INT_MIN;
            else          l1 = arr1[cut1 - 1];
            
            if(cut2 == 0) l2 = INT_MIN;
            else          l2 = arr2[cut2 - 1];
            
            if(cut1 == n) r1 = INT_MAX;
            else          r1 = arr1[cut1];
            
            if(cut2 == m) r2 = INT_MAX;
            else          r2 = arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }
            else if(l1 > r2){
                hi = cut1 - 1;
            }
            else{
                lo = cut1 + 1;
            }
        }
    }

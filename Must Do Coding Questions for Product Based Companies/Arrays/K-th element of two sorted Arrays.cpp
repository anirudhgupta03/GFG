//Method - 1
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

 //Method - 2
  class Solution{
      public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m) return kthElement(arr2,arr1,m,n,k);
        
        int l = 0, r = n;
        
        while(l <= r){
            
            int cut1 = (l + r)/2;
            int cut2 = k - cut1;
            
            if(cut2 > m){
                l = cut1 + 1;
                continue;
            }
            if(cut2 < 0){
                r = cut1 - 1;
                continue;
            }
            int a1,b1;
            
            if(cut1 == 0){
                a1 = INT_MIN;
                b1 = arr1[cut1];
            }
            else if(cut1 == n){
                a1 = arr1[n-1];
                b1 = INT_MAX;
            }
            else{
                a1 = arr1[cut1-1];
                b1 = arr1[cut1];
            }
            
            int a2,b2;
            
            if(cut2 == 0){
                a2 = INT_MIN;
                b2 = arr2[cut2];
            }
            else if(cut2 == m){
                a2 = arr2[m-1];
                b2 = INT_MAX;
            }
            else{
                a2 = arr2[cut2-1];
                b2 = arr2[cut2];
            }
            
            if(a1 <= b2 && a2 <= b1){
                return max(a1,a2);
            }
            else if(a1 > b2){
                r = cut1 - 1;
            }
            else{
                l = cut1 + 1;
            }
        }
    }
}

//Ref: https://www.youtube.com/watch?v=kQ1mJlwW-c0&t=19s
class Solution{  
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    #define ll long long
    void merge(long long arr[], long long l, long long mid, long long r, long long &count){
        
        long long n1 = mid - l + 1;
        long long n2 = r - mid;
        
        long long temp1[n1], temp2[n2];
        
        for(ll i = l; i <= mid; i++){
            temp1[i-l] = arr[i];
        }
        for(ll i = mid + 1; i <= r; i++){
            temp2[i-mid-1] = arr[i];
        }
        
        ll p1 = 0, p2 = 0, p3 = l;
        
        while(p1 < n1 && p2 < n2){
            
            if(temp1[p1] > temp2[p2]){
                count += n1 - p1;
                arr[p3] = temp2[p2];
                p2++;
                p3++;
            }
            else{
                arr[p3] = temp1[p1];
                p1++;
                p3++;
            }
        }
        
        while(p1 < n1){
            arr[p3] = temp1[p1];
            p1++;
            p3++;
        }
        while(p2 < n2){
            arr[p3] = temp2[p2];
            p2++;
            p3++;
        }
    }
    void mergesort(long long arr[], long long l ,long long r, long long &count){
        
        if(l < r){
            long long mid = (l + r)/2;
            mergesort(arr,l,mid,count);
            mergesort(arr,mid+1,r,count);
            merge(arr,l,mid,r,count);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0;
        mergesort(arr,0,N-1,count);
        return count;
    }

};

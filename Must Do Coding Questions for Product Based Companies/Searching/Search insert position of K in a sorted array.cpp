class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int ind;
        
        int lo = 0, hi = N - 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(Arr[mid] > k){
                ind = mid;
                hi = mid - 1;
            }
            else if(Arr[mid] < k){
                lo = mid + 1;
            }
            else{
                ind = mid;
                break;
            }
        }
        
        return ind;
    }
};

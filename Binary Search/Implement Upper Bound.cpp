class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int lo = 0, hi = n - 1, ans = n;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] > target){
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

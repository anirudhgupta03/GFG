//Ref: https://www.youtube.com/watch?v=6zhGS79oQ4k&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=2
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int lo = 0, hi = n - 1, ans = n;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] >= target){
                ans = mid;
                hi = mid - 1;
            }
            else if(arr[mid] < target){
                lo = mid + 1;
            }
        }
        return ans;
    }
};

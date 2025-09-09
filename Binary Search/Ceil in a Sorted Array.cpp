//Ref: https://www.youtube.com/watch?v=6zhGS79oQ4k&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=2
// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int ans = -1;
        
        int lo = 0, hi = n - 1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] >= x){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};

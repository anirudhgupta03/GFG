//Ref: https://www.youtube.com/watch?v=thUd_WJn6wk&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=19
class Solution {
  public:
    bool isPossibleToPaint(int mid, vector<int>& arr, int k){
        int timeTaken = 0, painters = 1;
        for(int i = 0; i < arr.size(); i++){
            timeTaken += arr[i];
            if(timeTaken > mid){
                painters++;
                timeTaken = arr[i];
            }
        }
        return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int lo = INT_MIN, hi = 0;
        for(int &ele: arr){
            lo = max(ele, lo);
            hi += ele;
        }
        int ans;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossibleToPaint(mid, arr, k)){
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

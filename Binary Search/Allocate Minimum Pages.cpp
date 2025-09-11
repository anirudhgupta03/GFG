//Ref: https://www.youtube.com/watch?v=Z0hwjftStI4&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=18
class Solution {
  public:
    bool isPossibleToAllocatePages(int pages, vector<int> &arr, int k){
        int students = 1, sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(sum > pages){
                students++;
                sum = arr[i];
            }
        }
        return students <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()){
            return -1;
        }
        int lo = INT_MIN, hi = 0;
        for(int &pages: arr){
            lo = max(lo, pages);
            hi += pages;
        }
        int ans;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossibleToAllocatePages(mid, arr, k)){
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

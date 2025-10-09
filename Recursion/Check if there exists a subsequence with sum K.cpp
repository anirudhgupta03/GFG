class Solution {
  public:
    bool solve(int ind, int n, vector<int>& arr, int k){
        if(k == 0) return true;
        if(ind == n) return false;
        if(arr[ind] <= k){
            return solve(ind + 1, n, arr, k - arr[ind]) || solve(ind + 1, n, arr, k);
        }
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        sort(arr.begin(), arr.end());
        return solve(0, n, arr, k);
    }
};

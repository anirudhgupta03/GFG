class Solution {
  public:
    void solve(int lo, int hi, vector<int> &arr){
        if(lo >= hi){
            return;
        }
        swap(arr[lo], arr[hi]);
        solve(lo + 1, hi - 1, arr);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        solve(0, arr.size() - 1, arr);
    }
};

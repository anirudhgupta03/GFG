class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        return upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);
    }
};

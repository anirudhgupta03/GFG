// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m = arr.size(), n = arr[0].size();
        int ind = -1, max1s = 0;
        
        for(int i = 0; i < m; i++){
            int count1s = n - (upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin());
            if(count1s > max1s){
                max1s = count1s;
                ind = i;
            }
        }
        return ind;
    }
};

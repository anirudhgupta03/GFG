//Ref: https://www.youtube.com/watch?v=Q9wXgdxJq48
class Solution {
  public:
    int numberOfElementsLessThanMid(int ele, vector<vector<int>> &mat){
        int m = mat.size(), n = mat[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            count += upper_bound(mat[i].begin(), mat[i].end(), ele) - mat[i].begin();
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size(), n = mat[0].size();
        int lo = INT_MAX, hi = INT_MIN;
        
        for(int i = 0; i < m; i++){
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][n - 1]);
        }
        
        int medianElements = (1 + m*n)/2;
        int ans;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(numberOfElementsLessThanMid(mid, mat) >= medianElements){
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

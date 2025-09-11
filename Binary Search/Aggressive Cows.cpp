//Ref: https://www.youtube.com/watch?v=R_Mfw4ew-Vo&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=17
class Solution {
  public:
    bool isPossibleToAccomodateCows(int minDistance, vector<int>& stalls, int k){
        int prePos = stalls[0], cows = 1;
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - prePos >= minDistance){
                cows++;
                prePos = stalls[i];
            }
        }
        return cows >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int lo = 1, hi = stalls[n - 1] - stalls[0];
        int ans;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossibleToAccomodateCows(mid, stalls, k)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};

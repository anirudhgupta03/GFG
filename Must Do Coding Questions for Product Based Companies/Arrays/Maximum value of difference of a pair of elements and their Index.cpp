//Time Complexity - O(N)
//Space Complexity - O(N)
class Solution {
  public:
    int maxValue(int arr[], int N) {
        
        int temp1[N], temp2[N];
        
        int mine = INT_MAX, maxe = INT_MIN;
        for(int i = 0; i < N; i++){
            temp1[i] = arr[i] + i;
            mine = min(mine,temp1[i]);
            maxe = max(maxe,temp1[i]);
        }
        
        int res1 = maxe - mine;
        mine = INT_MAX, maxe = INT_MIN;
        
        for(int i = 0; i < N; i++){
            temp2[i] = arr[i] - i;
            mine = min(mine,temp2[i]);
            maxe = max(maxe,temp2[i]);
        }
        
        int res2 = maxe - mine;
        
        return max(res1,res2);
    }
};

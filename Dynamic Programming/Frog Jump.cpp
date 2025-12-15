class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        if(n == 1) return 0;
        if(n == 2) return abs(height[0] - height[1]);
        int cost1 = 0, cost2 = abs(height[0] - height[1]), cost;
        for(int i = 2; i < n; i++){
            int tcost1 = cost1 + abs(height[i] - height[i - 2]);
            int tcost2 = cost2 + abs(height[i] - height[i - 1]);
            cost = min(tcost1, tcost2);
            cost1 = cost2;
            cost2 = cost;
        }
        return cost;
    }
};

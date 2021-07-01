//Time Complexity - O(N^2)
//Space Complexity - O(1)
class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        
        sort(arr.begin(),arr.end());
        
        int minDiff = INT_MAX, minSum = INT_MAX;
        
        for(int i = 0; i <= arr.size() - 3; i++){
            
            int lo = i + 1, hi = arr.size() - 1;
            
            bool flag = false;
            
            while(lo < hi){
                
                int sum = arr[lo] + arr[hi] + arr[i];
                
                if(sum > target){
                    if(sum - target < minDiff){
                        minDiff = sum - target;
                        minSum = sum;
                    }
                    else if(sum - target == minDiff){
                        minSum = max(minSum,sum);
                    }
                    hi--;
                }
                else if(sum == target){
                    return target;
                }
                else{
                    if(target - sum < minDiff){
                        minDiff = target - sum;
                        minSum = sum;
                    }
                    else if(target - sum == minDiff){
                        minSum = max(minSum,sum);
                    }
                    lo++;
                }
            }
        }
        
        return minSum;
    }
};

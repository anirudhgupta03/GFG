//Good Question
class Solution
{
    public:
        int trailZeroCount(int n){
            
            int count = 0, t = 5;
            
            while(n){
                if(n/t == 0){
                    break;
                }
                count += n/t;
                t *= 5;
            }
            return count;
        }
        int findNum(int n)
        {
            int lo = 5, hi = 5*n, ans;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                int temp = trailZeroCount(mid);
                
                if(temp >= n){
                    ans = mid;
                    hi = mid - 1;
                }
                else if(temp < n){
                    lo = mid + 1;
                }
            }
            return ans;
        }
};

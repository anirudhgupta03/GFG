class Solution{
public:
    int canReach(long long a, long long b, long long x) {
        
        long long steps = abs(a) + abs(b);
        
        if(x < steps){
            return false;
        }
        
        if(x == steps){
            return true;
        }
        
        if(x > steps){
            long long diff = x - steps;
            if(diff % 2 == 0){
                return true;
            }
            else{
                return false;
            }
        }
    }
 };

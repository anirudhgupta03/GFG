class Solution
{
public:
    int trailingZeroes(int N)
    {
        int count = 0, num = 5;
        
        while(1){
            
            count += N/num;
            num *= 5;
            
            if(N/num == 0){
                break;
            }
        }
        
        return count;
    }
};

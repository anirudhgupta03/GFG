//Method - 1
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int maxLen = 0, currLen = 0;
        
        while(N){
            
            if(N % 2 == 1){
                currLen++;
            }
            else{
                maxLen = max(maxLen,currLen);
                currLen = 0;
            }
            
            N /= 2;
        }
        maxLen = max(maxLen,currLen);
        return maxLen;
    }
};
//Method - 2
class Solution
{
    public:
    int maxConsecutiveOnes(int x)
    {
         int count = 0;

    // Count the number of iterations to
    // reach x = 0.
    while (x!=0)
    {
        // This operation reduces length
        // of every sequence of 1s by one.
        x = (x & (x << 1));

        count++;
    }

    return count;
    }
};

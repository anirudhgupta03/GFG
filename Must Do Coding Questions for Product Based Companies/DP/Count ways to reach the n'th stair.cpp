class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        int mod = 1e9 + 7;
        
        int val1 = 1, val2 = 1, val3 = 1;

        for(int i = 2; i <= n; i++){
            val3 = (val1 + val2)%mod;
            val1 = val2;
            val2 = val3;
        }
        return val3;
    }
};

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        int mask = (1 << k);
        
        if((n & mask) != 0){
            return true;
        }
        
        return false;
    }
};

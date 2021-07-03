class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        unsigned int ans = 0;
        
        while(n){
            
            ans <<= 1;
            
            ans |= (n & 1);
            
            n >>= 1;
        }
        
        return ans;
    }
};

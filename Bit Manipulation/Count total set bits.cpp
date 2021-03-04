class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n == 0){
            return 0;
        }
        
        int x = 0;
        while((1 << x) <= n){
            x++;
        }
        x--;
        
        return (((1 << (x-1))*(x)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x)));
    }
};

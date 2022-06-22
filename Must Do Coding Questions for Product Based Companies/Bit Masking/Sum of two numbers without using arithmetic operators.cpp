//Method - 1
class Solution
{
    public:
    int sum(int a , int b)
    {
        int res = 0, carry = 0, i = 0;
        while(a || b){
            int bit1 = (a & 1);
            int bit2 = (b & 1);
            
            int bit = bit1 ^ bit2 ^ carry;
            carry = bit1 & bit2 | bit1 & carry | bit2 & carry;
           
            if(bit) res |= (1 << i);
            a >>= 1;
            b >>= 1;
            i++;
        }
        if(carry) res |= (1 << i);
        return res;
    }
};

//Method - 2
class Solution
{
    public:
    int sum(int a , int b)
    {
        while(b){
            
            int carry = a & b;
            
            a = a ^ b;
            
            b = carry << 1;
        }
        return a;
    }
};

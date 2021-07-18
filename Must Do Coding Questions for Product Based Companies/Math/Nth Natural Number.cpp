class Solution{
	public:
    long long findNth(long long N)
    {
        long long n = 0 , mult = 1;
        
        while(N){
            long long temp = mult * (N % 9);
            n += temp;
            mult *= 10;
            N /= 9;
        }
        return n;
    }
 };

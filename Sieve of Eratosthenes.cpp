class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> prime(N+1,1);
        for(int p = 2; p * p <= N; p++)
        {
            if(prime[p] == 1){
                for(int i = p*p; i <= N; i+= p)
                {
                    prime[i] = 0;
                }
            }
        }
        vector<int> v;
        for(int i = 2; i <= N; i++)
        {
            if(prime[i]){
                v.push_back(i);
            }
        }
        return v;
    }
};

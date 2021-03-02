class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        vector<long long> sum(N+1,1);
        for(int i = 2; i < N + 1; i++){
            sum[i] += i;
        }
        
        for(int p = 2; p*p <= N; p++){
            sum[p*p] += p;
            for(int i = p*p+p; i<=N; i+=p){
                sum[i] += p + i/p;
            }
        }
        
        long long ans = 0;
        for(int i = 1; i <= N; i++){
            ans += sum[i];
        }
        return ans;
    }
};

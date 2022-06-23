class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        
        sort(A, A + N);
        
        vector<int> prefix(N + 1, 0);
        
        for(int i = 1; i <= N; i++){
            prefix[i] = prefix[i - 1] + A[i - 1];
        }
        
        int ans = INT_MAX, coins = 0;
        
        for(int i = 0; i < N; i++){
            
            int lo = i + 1, hi = N - 1, ele = A[i] + K, ind = N;
            
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if(A[mid] > ele){
                    ind = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            
            ans = min(ans, coins + prefix[N] - prefix[ind] - ele*(N - ind));
            coins += A[i];
        }
        return ans;
    }
};

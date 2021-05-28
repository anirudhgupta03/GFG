class Solution{
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        
        int ans = INT_MIN;
        
        int sum = 0;
        
        for(int i = 0; i < K; i++){
            sum += Arr[i];
        }
        
        ans = max(ans,sum);
        
        int l = 0, r = K;
        
        while(r < N){
            
            sum = sum - Arr[l] + Arr[r];
            ans = max(ans,sum);
            
            l++;
            r++;
        }
        
        return ans;
    }
};

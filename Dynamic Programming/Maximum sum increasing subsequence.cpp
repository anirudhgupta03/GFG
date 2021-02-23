class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    dp[0] = arr[0];
	    
	    int ans = dp[0],temp;
	    for(int i = 1; i < n; i++)
      {
	        temp = arr[i];
	        for(int j = 0; j < i; j++)
          {
	            if(arr[i] > arr[j])
              {
	                temp = max(arr[i]+dp[j],temp);
	            }
	        }
	        dp[i] = temp;
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}  
};

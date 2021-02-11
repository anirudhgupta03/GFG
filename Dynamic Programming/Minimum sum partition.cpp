class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum = 0;
	    
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    
	    int dp[n+1][sum+1];
	    for(int i = 0; i < n + 1; i++){
	        dp[i][0] = 1;
	    }
	    for(int j = 1; j < sum + 1; j++){
	        dp[0][j] = 0;
	    }
	    
	    for(int i = 1; i < n + 1; i++){
	        for(int j = 1; j < sum + 1; j++){
	            
	            if(arr[i-1] <= j){
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    vector<int> v;
	    
	    for(int j = 0; j <= sum/2; j++){
	        if(dp[n][j]){
	            v.push_back(j);
	        }
	    }
	    
	    int mindiff = INT_MAX;
	    for(int i = 0; i < v.size(); i++){
	        mindiff = min(mindiff,sum - 2*v[i]);
	    }
	    
	    return mindiff;
	} 
};

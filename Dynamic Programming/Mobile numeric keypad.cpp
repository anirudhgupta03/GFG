class Solution{
public:
	#define ll long long
	long long getCount(int N)
	{
		ll dp[N+1][10];
		
		for(int i = 0; i <= N; i++){
		    for(int j = 0; j < 10; j++){
		        
		        if(i == 0){
		            dp[i][j] = 0;
		        }
		        else if(i == 1){
		            dp[i][j] = 1;
		        }
		        else{
		            dp[i][j] = dp[i-1][j];
		            if(j == 0) dp[i][j] += dp[i-1][8];
		            if(j == 1) dp[i][j] += dp[i-1][2] + dp[i-1][4];
		            if(j == 2) dp[i][j] += dp[i-1][1] + dp[i-1][3] + dp[i-1][5];
		            if(j == 3) dp[i][j] += dp[i-1][2] + dp[i-1][6];
		            if(j == 4) dp[i][j] += dp[i-1][1] + dp[i-1][5] + dp[i-1][7];
		            if(j == 5) dp[i][j] += dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8];
		            if(j == 6) dp[i][j] += dp[i-1][5] + dp[i-1][9] + dp[i-1][3];
		            if(j == 7) dp[i][j] += dp[i-1][4] + dp[i-1][8];
		            if(j == 8) dp[i][j] += dp[i-1][0] + dp[i-1][5] + dp[i-1][7] + dp[i-1][9];
		            if(j == 9) dp[i][j] += dp[i-1][6] + dp[i-1][8];
 		        }
		    }
		}
		
		ll ans = 0;
		
		for(int j = 0; j < 10; j++){
		    ans += dp[N][j];
		}
		return ans;
	}


};

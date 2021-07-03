class Solution{
public:
		int CountWays(string str){
		    
		    int mod = 1e9 + 7;
		    
		    if(str[0] == '0'){
		        return 0;
		    }
		    
		    int n = str.size();
		    
		    int dp[n];
		    dp[0] = 1;
		    
		    for(int i = 1; i < n; i++){
		        
		        if(str[i] != '0' && str[i-1] != '0'){
		            string s = str.substr(i-1,2);
		            int n = stoi(s);
		            
		            dp[i] = dp[i-1];
		            
		            if(n >= 1 && n <= 26){
		                if(i >= 2){
		                    dp[i] = (dp[i] + dp[i-2])%mod;
		                }
		                else{
		                    dp[i] = (dp[i] + 1)%mod;
		                }
		            }
		        }
		        else if(str[i] != '0' && str[i-1] == '0'){
		            dp[i] = dp[i-1];
		        }
		        else if(str[i] == '0' && str[i-1] != '0'){
		            if(str[i-1] == '1' || str[i-1] == '2'){
		                if(i >= 2){
		                    dp[i] = dp[i-2];
		                }
		                else{
		                    dp[i] = 1;
		                }
		            }
		            else{
		                dp[i] = 0;
		            }
		        }
		        else if(str[i] == '0' && str[i-1] == '0'){
		            dp[i] = 0;
		        }
		    }
		    return dp[n - 1];
		}
        
};

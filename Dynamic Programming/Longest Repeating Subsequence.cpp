class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    
		    string p;
		    for(int i = 0; i < str.size(); i++){
		        p.push_back(str[i]);
		    }
		    
		    int dp[str.size()+1][p.size()+1];
		    
		    for(int j = 0; j < p.size()+1; j++){
		        dp[0][j] = 0;
		    }
		    for(int i = 0; i < str.size()+1; i++){
		        dp[i][0] = 0;
		    }
		    
		    for(int i = 1; i < str.size() + 1; i++){
		        for(int j = 1; j < p.size() + 1; j++){
		            
		            if(str[i-1] == p[j-1] && i!=j){
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    
		    return dp[str.size()][p.size()];
		}

};

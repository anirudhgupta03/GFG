//Recursive Approach
//Time Complexity - O(2^N)
//Space Complexity - O(1)
class Solution{
	    public:
	    int solve(int n1, int n2, string s1, string s2){
	        
	        if(n1 == 0 || n2 == 0){
	            return 0;
	        }
	        
	        if(s1[n1-1] == s2[n2-1] && n1 != n2){
	            return 1 + solve(n1-1,n2-1,s1,s2);
	        }
	        else{
	            return max(solve(n1-1,n2,s1,s2), solve(n1,n2-1,s1,s2));
	        }
	    }
		int LongestRepeatingSubsequence(string str){
		    
		    int n = str.size();
		    return solve(n,n,str,str);
		}

};

//Top-Down Approach
//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
class Solution{
	    public:
	    int solve(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp){
	        
	        if(n1 == 0 || n2 == 0){
	            return dp[n1][n2] = 0;
	        }
	        
	        if(dp[n1][n2] != -1){
	            return dp[n1][n2];
	        }
	        if(s1[n1-1] == s2[n2-1] && n1 != n2){
	            return dp[n1][n2] = 1 + solve(n1-1,n2-1,s1,s2,dp);
	        }
	        else{
	            return dp[n1][n2] = max(solve(n1-1,n2,s1,s2,dp), solve(n1,n2-1,s1,s2,dp));
	        }
	    }
		int LongestRepeatingSubsequence(string str){
		    
		    int n = str.size();
		    
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    
		    return solve(n,n,str,str,dp);
		}

};

//Bottom-Up Approach
//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
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

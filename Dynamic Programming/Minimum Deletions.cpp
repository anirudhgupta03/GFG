#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    string s;
	    cin >> s;
	    
	    string p;
	    for(int i = s.size() - 1; i >= 0; i--){
	        p.push_back(s[i]);
	    }
	    
	    int dp[s.size() + 1][p.size() + 1];
	    
	    for(int j = 0; j < s.size() + 1; j++){
	        dp[0][j] = 0;
	    }
	    
	    for(int i = 0; i < p.size() + 1; i++){
	        dp[i][0] = 0;
	    }
	    
	    for(int i = 1; i < s.size() + 1; i++){
	        for(int j = 1; j < p.size() + 1; j++){
	            
	            if(s[i-1] == p[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	            }
	        }
	    }
	    
	    cout << s.size() - dp[s.size()][p.size()] << endl;
	}
	return 0;
}

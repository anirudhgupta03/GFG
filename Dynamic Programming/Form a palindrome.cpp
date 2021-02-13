#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int t;
	cin >> t;
	
	while(t--){
	    string s;
	    cin >> s;
	    
	    string rev;
	    for(int i = s.size() - 1; i >= 0; i--){
	        rev.push_back(s[i]);
	    }
	    
	    int dp[s.size() + 1][rev.size() + 1];
	    
	    for(int j = 0; j < rev.size() + 1; j++){
	        dp[0][j] = 0;
	    }
	    for(int i = 0; i < s.size() + 1; i++){
	        dp[i][0] = 0;
	    }
	    
	    for(int i = 1; i < rev.size() + 1; i++){
	        for(int j = 1; j < s.size() + 1; j++){
	            
	            if(s[i-1] == rev[j-1]){
	                dp[i][j] = dp[i-1][j-1] + 1;
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    
	    cout << s.size() - dp[s.size()][rev.size()] << endl;
	}
	return 0;
}

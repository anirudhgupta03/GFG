//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
            
            int n = a.size(), m = b.size();
            
            int dp[n+1][m+1];
            
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= m; j++){
                    
                    if(i == 0 || j == 0){
                        dp[i][j] = 0;
                    }
                    else if(a[i-1] == b[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            
            int i = n, j = m;
            
            vector<int> res;
            
            while(i != 0 && j != 0){
                
                if(a[i-1] == b[j-1]){
                    res.push_back(a[i-1]);
                    i--;
                    j--;
                }
                else{
                    
                    if(dp[i-1][j] > dp[i][j-1]){
                        i--;
                    }
                    else{
                        j--;
                    }
                }
            }
            reverse(res.begin(),res.end());
            return res;
}

//Method - 2
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
            
            int  m = a.size(), n = b.size();
            
            string dp[m+1][n+1];
            
            for(int i = 0; i <= m; i++){
                for(int j = 0; j <= n; j++){
                    
                    if(i == 0 || j == 0){
                        dp[i][j] = "";
                    }
                    else if(a[i-1] == b[j-1]){
                        dp[i][j] = dp[i-1][j-1] + to_string(a[i-1]) + " ";
                    }
                    else{
                        if(dp[i-1][j].size() > dp[i][j-1].size())
                        dp[i][j] = dp[i-1][j];
                        else
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
            
            stringstream X(dp[m][n]);
            
            vector<int> res;
            
            string temp;
            
            while(X >> temp){
                res.push_back(stoi(temp));
            }
            
            return res;
}

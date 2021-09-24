//https://www.codingninjas.com/codestudio/problems/shuffle-two-strings_1115692?leftPanelTab=0
//Method - 1
//TLE
bool solve(string a, string b, string c, int n1, int n2, int n3){
    
    if(n1 == 0 && n2 == 0 && n3 == 0){
        return true;
    }
    
    if(n1 > 0 && n2 > 0 && a[n1 - 1] == c[n3 - 1] && b[n2 - 1] == c[n3 - 1]){
        return solve(a, b, c, n1 - 1, n2, n3 - 1) || solve(a, b, c, n1, n2 - 1, n3 - 1);
    }
    else if(n1 > 0 && a[n1 - 1] == c[n3 - 1]){
        return solve(a, b, c, n1 - 1, n2, n3 - 1);
    }
    else if(n2 > 0 && b[n2 - 1] == c[n3 - 1]){
        return solve(a, b, c, n1, n2 - 1, n3 - 1);
    }
    else{
        return false;
    }
}
bool isInterleave(string a, string b, string c){
	
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    
    if(n1 + n2 != n3){
        return false;
    }
    
    return solve(a, b, c, n1, n2, n3);
}

//Method - 2
//DP
bool solve(string a, string b, string c, int n1, int n2, int n3, vector<vector<int>> &dp){
    
    if(n1 == 0 && n2 == 0 && n3 == 0){
        return true;
    }
    
    if(dp[n1][n2] != -1){
        return dp[n1][n2];
    }
    
    if(n1 > 0 && n2 > 0 && a[n1 - 1] == c[n3 - 1] && b[n2 - 1] == c[n3 - 1]){
        return dp[n1][n2] = solve(a, b, c, n1 - 1, n2, n3 - 1, dp) || solve(a, b, c, n1, n2 - 1, n3 - 1, dp);
    }
    else if(n1 > 0 && a[n1 - 1] == c[n3 - 1]){
        return dp[n1][n2] = solve(a, b, c, n1 - 1, n2, n3 - 1, dp);
    }
    else if(n2 > 0 && b[n2 - 1] == c[n3 - 1]){
        return dp[n1][n2] = solve(a, b, c, n1, n2 - 1, n3 - 1, dp);
    }
    else{
        return dp[n1][n2] = false;
    }
}
bool isInterleave(string a, string b, string c){
	
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    
    if(n1 + n2 != n3){
        return false;
    }
    
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return solve(a, b, c, n1, n2, n3, dp);
}

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void solve(int ind, string &s, vector<vector<string>> &res, vector<string> &temp){
    
    if(ind == s.size()){
        res.push_back(temp);
        return;
    }
    
    for(int i = ind; i < s.size(); i++){
        
        string str = s.substr(ind, i - ind + 1);
        if(isPalindrome(str)){
            temp.push_back(str);
            solve(i + 1, s, res, temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res;
    vector<string> temp;
    solve(0, s, res, temp);
    return res;
}

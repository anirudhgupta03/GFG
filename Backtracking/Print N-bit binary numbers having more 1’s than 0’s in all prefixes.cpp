#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &v, string &s, int n, int count1, int count2){
    
    if(count1 + count2 == n){
        v.push_back(s);
        return;
    }
    
    s.push_back('1');
    solve(v,s,n,count1+1,count2);
    s.pop_back();
    if(count1 > count2){
        s.push_back('0');
        solve(v,s,n,count1,count2+1);
        s.pop_back();
    }
}
int main() {
    
    int n;
    cin >> n;
    
    vector<string> v;
    string s;
    
    solve(v,s,n,0,0);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
	return 0;
}

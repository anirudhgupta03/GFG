#include <bits/stdc++.h>
using namespace std;

void solve(string op, int count1, int count2, int n){
    
    if(count1 + count2 == n){
        cout << op << endl;
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    if(count1 > count2){
        
        op1.push_back('1');
        op2.push_back('0');
        
        solve(op1,count1+1,count2,n);
        solve(op2,count1,count2+1,n);
    }
    else if(count1 == count2){
        
        op1.push_back('1');
        solve(op1,count1+1,count2,n);
    }
}
int main(){
    
    int n;
    cin >> n;
    
    string op;
    
    int cnt1 = 0, cnt2 = 0;
    solve(op,cnt1,cnt2,n);
	return 0;
}

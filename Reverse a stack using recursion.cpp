#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp){
    
    if(s.size() == 0){
        s.push(temp);
        return;
    }
    
    int t = s.top();
    s.pop();
    insert(s,temp);
    s.push(t);
}

void solve(stack<int> &s){
    
    if(s.size() == 1){
        return;
    }
    
    int temp = s.top();
    
    s.pop();
    
    solve(s);
    
    insert(s,temp);
}
int main() {
    
    stack<int> s;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        s.push(x);
    }
    
    solve(s);
    
    for(int i = 0; i < n; i++){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
	return 0;
}

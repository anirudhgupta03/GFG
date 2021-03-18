#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp, int n){
    
    if(v.size() == 0){
        v.push_back(temp);
        return;
    }
    
    if(temp >= v[n-1]){
        v.push_back(temp);
        return;
    }
    
    int t = v[n-1];
    v.pop_back();
    insert(v,temp,n-1);
    v.push_back(t);
}

void solve(vector<int> &v, int n){
    
    if(n == 1){
        return;
    }
    
    int temp = v[n-1];
    
    v.pop_back();
    
    solve(v,n-1);
    
    insert(v,temp,n-1);
}
int main() {
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    solve(v,n);
    
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
	return 0;
}

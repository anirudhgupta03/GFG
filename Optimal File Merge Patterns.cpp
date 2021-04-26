#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int file[n];
    
    for(int i = 0; i < n; i++){
        cin >> file[i];
    }
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    int cost = 0;
    
    for(int i = 0; i < n; i++){
        pq.push(file[i]);
    }
    
    while(pq.size() != 1){
        
        int file1 = pq.top();
        pq.pop();
        
        int file2 = pq.top();
        pq.pop();
        
        cost += file1 + file2;
        
        pq.push(file1 + file2);
    }
    
    cout << cost << endl;
	  return 0;
}

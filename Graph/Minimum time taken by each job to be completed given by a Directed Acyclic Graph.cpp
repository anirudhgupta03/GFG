#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int v,e;
    cin >> v >> e;
    
    vector<int> al[v+1];
    
    vector<int> in(v+1,0);
    while(e--){
        int a,b;
        cin >> a >> b;
        al[a].push_back(b);
        in[b]++;
    }
    
    vector<int> res(v+1);
    queue<pair<int,int>> q;
    
    for(int i = 1; i <= v; i++){
        if(in[i] == 0){
            q.push({i,1});
        }
    }
    
    while(!q.empty()){
        
        int curr = q.front().first, t = q.front().second;
        res[curr] = t;
        q.pop();
        
        for(int i = 0; i < al[curr].size(); i++){
            in[al[curr][i]]--;
            if(in[al[curr][i]] == 0){
                q.push({al[curr][i],t+1});
            }
        }
    }
    
    for(int i = 1; i <= v; i++){
        cout << res[i] << " ";
    }
    cout << endl;
	return 0;
}

/*
Input
10 13
1 3
1 4
1 5
2 3
2 9
2 8
3 6
4 6 
4 8
5 8
6 7
7 8
8 10 

Output
1 1 2 2 2 3 4 5 2 6 
/*

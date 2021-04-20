#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    stack<int> s;
    vector<int> ans;
    
    ans.push_back(-1);
    
    s.push(arr[0]);
    
    for(int i = 1; i < n; i++){
        
        if(arr[i] < s.top()){
            ans.push_back(s.top());
        }
        else{
            
            while(!s.empty() && arr[i] >= s.top()){
                s.pop();
            }
            
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

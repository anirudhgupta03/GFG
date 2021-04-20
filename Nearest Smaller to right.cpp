//Nearest Smaller to right
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> ans;
    ans.push_back(-1);
    
    stack<int> s;
    s.push(arr[n-1]);
    
    for(int i = n - 2; i >= 0; i--){
        
        if(arr[i] > s.top()){
            ans.push_back(s.top());
        }
        else{
            
            while(!s.empty() && arr[i] <= s.top()){
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
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

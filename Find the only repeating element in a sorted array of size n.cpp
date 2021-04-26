#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int lo = 0, hi = n - 1, ans;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(arr[mid] == mid + 1){
            lo = mid + 1;
        }
        else if(arr[mid] == mid){
            hi = mid - 1;
            ans = arr[mid];
        }
    }
    cout << ans << endl;
}

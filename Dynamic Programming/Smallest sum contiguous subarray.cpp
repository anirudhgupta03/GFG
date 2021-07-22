#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int currSum = 0, minSum = INT_MAX;
    
    for(int i = 0; i < n; i++){
        
        currSum += arr[i];
        
        minSum = min(minSum,currSum);
        
        if(currSum > 0){
            currSum = 0;
        }
    }
	  cout << minSum << endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    int temp=a[n-1];
	    for(int i=n-1;i>=1;i--){
	        a[i]=a[i-1];
	    }
	    a[0]=temp;
	    
	    for(int i=0;i<n;i++){
	        cout << a[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    int a[n],b[m];
	    
	    unordered_map<int,int> umap;
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        umap[a[i]]++;
	    }
	    
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	        umap[b[i]]++;
	    }
	    
	    cout << umap.size() << endl;
	}
	return 0;
}

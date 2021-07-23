#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> temp){
    
    int sum = 0;
    
    unordered_map<int,int> umap;
    
    vector<int> v(3);
    
    int maxLen = 0, start = -1, end = -1;
    
    for(int i = 0; i < temp.size(); i++){
        
        sum += temp[i];
        
        if(sum == 0){
            start = 0;
            end = i;
            maxLen = i + 1;
            continue;
        }
        
        if(umap.find(sum) != umap.end()){
            if(i - umap[sum] > maxLen){
                maxLen = i - umap[sum];
                start = umap[sum] + 1;
                end = i;
            }
        }
        else{
            umap[sum] = i;
        }
    }
    
    v[0] = maxLen;
    v[1] = start;
    v[2] = end;
    return v;
}
int main() {
    
    int n,m;
    cin >> n >> m;
    
    int mat[n][m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    
    vector<vector<int>> res;
    
    int maxRec = 0;
    
    int top, left, bottom, right;
    
    for(int i = 0; i < n; i++){
        
        vector<int> temp(m,0);
        for(int j = i; j < n; j++){
            
            for(int k = 0; k < m; k++){
                temp[k] += mat[j][k];
            }
            
            int l = j - i + 1;
            
            vector<int> vec = solve(temp);
            
            if(l * vec[0] > maxRec){
                top = i;
                bottom = j;
                left = vec[1];
                right = vec[2];
                maxRec = l * vec[0];
            }
        }
    }
    
	for(int i = top; i <= bottom; i++){
	    for(int j = left; j <= right; j++){
	        cout << mat[i][j] << " ";
	    }
	    cout << endl;
	}
}

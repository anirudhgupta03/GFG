//https://www.codingninjas.com/codestudio/problems/common-elements-present-in-all-rows-of-a-matrix_1118111?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    unordered_map<int,int> umap;
    int n = mat.size(), m = mat[0].size();
    
    vector<int> common;
    
    if(n == 1){
     	for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                common.push_back(mat[i][j]);
            }
        }   
        return common;
    }
    
    for(int j = 0; j < m; j++){
        umap[mat[0][j]] = 1;
    }
   
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(umap[mat[i][j]] == i){
                umap[mat[i][j]] = i + 1;
                
                if(i == n - 1 && umap[mat[i][j]] == n){
                    common.push_back(mat[i][j]);
                }
            }
        }
    }
    return common;
}

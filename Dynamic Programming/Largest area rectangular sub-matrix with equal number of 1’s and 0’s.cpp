//https://www.codingninjas.com/codestudio/problems/largest-submatrix-with-equal-number-of-0-s-and-1-s_1062689?leftPanelTab=1
#include<bits/stdc++.h>
using namespace std;

int kadane(int l, vector<int> &temp){
    
    int maxLen = 0, sum = 0;
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < temp.size(); i++){
        
        int zeros = l - temp[i];
        
        sum += temp[i] - zeros;
        
        if(sum == 0){
            maxLen = i + 1;
            continue;
        }
        
        if(umap.find(sum) != umap.end()){
            maxLen = max(maxLen, i - umap[sum]);
        }
        else{
            umap[sum] = i;
        }
    }
    
    return maxLen;
}
int maximumArea(vector<vector<int>>& mat, int n, int m)
{
    int maxArea = 0;
    
    for(int i = 0; i < n; i++){
        
        vector<int> temp(m,0);
        
        for(int j = i; j < n; j++){
            
            for(int k = 0; k < m; k++){
                temp[k] += mat[j][k];
            }
            
            int l = j - i + 1;
            maxArea = max(maxArea , l*kadane(l,temp));
        }
    }
    return maxArea;
}

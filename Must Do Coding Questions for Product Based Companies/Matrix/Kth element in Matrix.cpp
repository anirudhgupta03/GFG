//Ref1: https://www.youtube.com/watch?v=G5wLN4UweAM
//Ref2: https://www.youtube.com/watch?v=dpsp1hP6P-U
int count(int mid, int mat[][MAX], int n){
    
    int c = 0, i = n - 1, j = 0;
    
    while(i >= 0 && j < n){
        
        if(mat[i][j] > mid){
            i--;
        }
        else{
            c += i + 1;
            j++;
        }
    }
    return c;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int lo = mat[0][0], hi = mat[n-1][n-1];
    
    int ans;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(count(mid, mat, n) >= k){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    
    return ans;
}

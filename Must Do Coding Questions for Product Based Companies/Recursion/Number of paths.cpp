long long numberOfPaths(int m, int n){
    long long count = 1;
    
    m -= 1;
    n -= 1;
    
    for(int i = 1; i <= m; i++){
        
        count = count*(m + n - i + 1);
        count /= i;
    }
    
    return count;
}

class Solution{
    public:
    void reverse(string &num, int i, int j)
    {
        while (i < j) {
            swap(num[i], num[j]);
            i++;
            j--;
        }
    }
    string nextPalin(string N) { 
        
        if(N.size() <= 3){
            return "-1";
        }
        
        int mid = N.size()/2 - 1;
        int i,j;
        
        for(i = mid - 1; i >= 0; i--){
            if(N[i] < N[i+1]){
                break;
            }
        }
        
        if(i < 0){
            return "-1";
        }
        
        int smallest = i + 1;
        for(int j = i + 2; j <= mid; j++){
            if(N[j] > N[i] && N[j] <= N[smallest]){
                smallest = j;
            }
        }
        
        swap(N[i],N[smallest]);
        
        swap(N[N.size()-i-1], N[N.size()- smallest - 1]);
        
        reverse(N,i+1,mid);
        
        if(N.size() % 2 == 0){
            reverse(N,mid + 1, N.size() - i -2);
        }
        else{
            reverse(N,mid+2,N.size() - i - 2);
        }
        return N;
    }
};

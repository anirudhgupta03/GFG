class Solution{
    public:
    int catchThieves(char a[], int n, int k) 
    {
        char arr[n];
        for(int i = 0; i < n; i++){
            arr[i] = a[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            
            if(a[i] == 'P'){
                
                int q = max(i-k,0);
                int r = min(n-1,i+k);
                
                int flag = 0;
                for(int j = q; j < i; j++){     //Search in the left side of police
                    if(arr[j] == 'T'){
                        arr[j] = 'P';
                        count++;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    for(int j = i + 1; j <= r; j++){    //Search in the right side of police
                        if(arr[j] == 'T'){
                            arr[j] = 'P';
                            count++;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};

//Very Good Question
class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int> arr(n,-1);
        
        for(int i = 0; i < n; i++){
            
            if(gallery[i] == 0){
                arr[i] = max(arr[i],i);
                continue;
            }
            if(gallery[i] != -1){
                
                int k = max(0,i - gallery[i]);
                
                for(int p = k; p <= min(n - 1,i + gallery[i]); p++){
                    
                    arr[p] = max(arr[p], min(n - 1, i + gallery[i]));
                }
            }
        }
        
        int count = 0, i = 0;
        while(i < n){
            
            if(arr[i] == -1){
                return -1;
            }
            i = arr[i];
            i++;
            count++;
        }
        return count;
    }
};

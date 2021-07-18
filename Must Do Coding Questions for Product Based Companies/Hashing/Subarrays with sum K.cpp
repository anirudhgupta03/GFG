class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        unordered_map<int,int> umap;
        
        int count = 0, sum = 0;
        
        for(int i = 0; i < N; i++){
            
            sum += Arr[i];
            
            if(sum == k){
                count++;
            }
            
            if(umap.find(sum - k) != umap.end()){
                count += umap[sum - k];
            }
            
            umap[sum]++;
        }
        return count;
    }
};

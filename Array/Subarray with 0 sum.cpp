class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,int> umap;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += arr[i];
            
            if(sum == 0){
                return true;
            }
            
            if(umap.find(sum) != umap.end()){
                return true;
            }
            
            umap[sum]++;
        }
        return false;
    }
};

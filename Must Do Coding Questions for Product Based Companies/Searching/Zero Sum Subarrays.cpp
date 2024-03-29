//Method - 1
class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        
        ll count = 0;
        
        unordered_map<ll,ll> umap;
        
        ll sum = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += arr[i];
            
            if(sum == 0){
                count++;
            }
            
            if(umap.find(sum) != umap.end()){
                count += umap[sum];
            }
            
            umap[sum]++;
        }
        
        return count;
    }
};

//Method - 2
class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        
        unordered_map<int,int> umap;
        
        ll count = 0, sum = 0;
        
        umap[0] = 1;
        
        for(int i = 0; i < n; i++){
            
            sum += arr[i];
            
            if(umap.find(sum) != umap.end()){
                count += umap[sum];
            }
            
            umap[sum]++;
        }
        
        return count;
    }
};

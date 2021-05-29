//Time Complexity: O(N) The entire array is traversed only once.
//Space Complexity: O(N) Hashmap can contain up to N distinct entries in the worst case.
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> umap;
        
        int max_size = 0;
        
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            
            sum += A[i];
            
            if(sum == K){
                max_size = max(max_size,i+1);
            }
            
            if(umap.find(sum-K) != umap.end()){
                max_size = max(max_size,i - umap[sum-K]);
            }
            
            if(umap.find(sum) == umap.end()){
                umap[sum] =  i;
            }
        }
        return max_size;
    } 

};

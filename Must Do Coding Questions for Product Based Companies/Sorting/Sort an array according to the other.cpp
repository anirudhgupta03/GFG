class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int,int> umap;
        
        for(int i = 0; i < N; i++){
            umap[A1[i]]++;
        }
        
        int p = 0;
        
        for(int i = 0; i < M; i++){
            
            if(umap.find(A2[i]) != umap.end()){
                int count = umap[A2[i]];
                umap.erase(A2[i]);
                
                while(count){
                    A1[p] = A2[i];
                    p++;
                    count--;
                }
            }
        }
        
        for(auto x: umap){
            
            int count = x.second;
            
            while(count){
                A1[p] = x.first;
                p++;
                count--;
            }
        }
        
        return A1;
    } 
};

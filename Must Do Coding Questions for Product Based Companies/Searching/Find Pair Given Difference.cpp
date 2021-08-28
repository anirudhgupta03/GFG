//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
bool findPair(int arr[], int size, int n){
   
   unordered_map<int,int> umap;
   
   for(int i = 0; i < size; i++){
       
       if(umap.find(arr[i]-n) != umap.end() || umap.find(arr[i]+n) != umap.end()){
           return true;
       }
       
       umap[arr[i]]++;
   }
   
   return false;
}

//Method - 2
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=5IUyc7cPD9E
bool findPair(int arr[], int size, int n){
    
    sort(arr,arr+size);
    
    for(int i = 0; i < size; i++){
        
        int ele = arr[i] + n;
        
        int lo = i + 1, hi = size - 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(arr[mid] == ele){
                return true;
            }
            else if(arr[mid] > ele){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
    }
    return false;
}

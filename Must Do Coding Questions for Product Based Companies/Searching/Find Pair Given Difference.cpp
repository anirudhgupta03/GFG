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

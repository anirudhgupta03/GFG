public:
    void merge(int arr[], int l, int m, int r)
    {
         int n1 = m - l + 1;
         int n2 = r - m;
         
         vector<int> left(n1);
         vector<int> right(n2);
         
         for(int i = l; i <= m; i++){
             left[i-l] = arr[i];
         }
         for(int i = m + 1; i <= r; i++){
             right[i-m-1] = arr[i];
         }
         
         int p1 = 0, p2 = 0, p3 = l;
         
         while(p1< n1 && p2 < n2){
             if(left[p1] < right[p2]){
                 arr[p3] = left[p1];
                 p1++;
             }
             else{
                 arr[p3] = right[p2];
                 p2++;
             }
             p3++;
         }
         while(p1 < n1){
             arr[p3] = left[p1];
             p1++;
             p3++;
         }
         while(p2 < n2){
             arr[p3] = right[p2];
             p2++;
             p3++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r){
            return;
        }
        
        int mid = (l + r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

class Solution{  
  public:

    int sb(int arr[], int n, int x)
    {
          int l = 0, r = 0, minLen = INT_MAX;
          
          int sum = 0;
          
          while(r < n){
              
              sum += arr[r];
              
              if(sum > x){
                  while(l <= r && sum > x){
                      minLen = min(minLen,r - l + 1);
                      sum -= arr[l];
                      l++;
                  }
              }
              r++;
          }
          
          return minLen;
    }
};

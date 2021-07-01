class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
       
       int lo = 0, hi = 0;
       
       int count = 0, maxLen = 0;
       
       while(hi < n){
           
           if(arr[hi] == 0){
               count++;
           }
           
           if(count > m){
               maxLen = max(maxLen,hi-lo);
               
               while(arr[lo] == 1 && lo < hi){
                   lo++;
               }
               lo++;
               count--;
           }
           hi++;
       }
       maxLen = max(maxLen,hi-lo);
       return maxLen;
    }  
};

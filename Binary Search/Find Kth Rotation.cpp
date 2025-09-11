//Method - 1
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        int lo = 0, hi = n - 1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int preEle = (mid - 1 >= 0) ? arr[mid - 1] : arr[n - 1];
            int nextEle = (mid + 1 < n) ?  arr[mid + 1] : arr[0];
            
            if(arr[mid] < preEle && arr[mid] < nextEle){
                return mid;
            }
            else if(arr[mid] <= arr[hi]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return -1;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=jtSiWTPLwd0&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=7
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        int lo = 0, hi = n - 1, ans = INT_MAX, index = -1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
          
            if(arr[lo] <= arr[hi]){
                if(arr[lo] < ans){
                    ans = arr[lo];
                    index = lo;
                }
                break;
            }
            if(arr[lo] <= arr[mid]){
                if(arr[lo] < ans){
                    ans = arr[lo];
                    index = lo;
                }
                lo = mid + 1;
            }
            else{
                if(arr[mid] < ans){
                    ans = arr[mid];
                    index = mid;
                }
                hi = mid - 1;
            }
        }
        return index;
    }
};

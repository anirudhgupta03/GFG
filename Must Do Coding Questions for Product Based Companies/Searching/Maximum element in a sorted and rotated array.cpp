//https://www.geeksforgeeks.org/maximum-element-in-a-sorted-and-rotated-array/
class Solution{
public:
    int findMax(int arr[], int n){
        
        if(n == 1){
            return arr[0];
        }
        if(n == 2){
            return max(arr[0],arr[1]);
        }
        int l = 0, r = n - 1;
        
        while(l <= r){
            
            int mid = (l + r)/2;
            int prev = (mid - 1 + n)%n, next = (mid + 1)%n;
            
            if(arr[mid] > arr[prev] && arr[mid] > arr[next]){
                return arr[mid];
            }
            else if(arr[mid] >= arr[l]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
};

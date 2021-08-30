//https://www.codingninjas.com/codestudio/problems/rotated-array_1093219?leftPanelTab=0
int rotatedArray(int arr[], int n)
{
    int lo = 0, hi = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        int prev = (mid - 1 + n)%n;
        int next = (mid + 1)%n;
        
        if(arr[mid] < arr[prev] && arr[mid] < arr[next]){
            return arr[mid];
        }
        else if(arr[mid] < arr[hi]){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
}

//Ref: https://www.youtube.com/watch?v=KtrAWsfyBaA
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    int ans = -1;
    int i = 0;
    
    while(i < n){
        if(arr[i] == x){
            ans = i;
            break;
        }
        
        i = i + max(1,abs(arr[i]-x)/k);
    }
    
    return ans;
}   

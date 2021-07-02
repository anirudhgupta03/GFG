//Ref: https://www.youtube.com/watch?v=PqEiJDdt3S4
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        
        int count = 0;
        
        for(int i = n - 1; i >= 2; i--){
            
            int lo = 0, hi = i - 1;
            
            while(lo < hi){
                
                if(arr[lo] + arr[hi] > arr[i]){
                    count += hi - lo;
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }
        return count;
    }
};

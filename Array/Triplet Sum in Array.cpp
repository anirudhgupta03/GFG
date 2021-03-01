class Solution{
    public:
    // function to find the triplet which sum to x
    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for 
    
    bool find3Numbers(int arr[], int N, int X)
    {
        sort(arr,arr+N);
        
        for(int i = 0; i < N - 2; i++){
            
            int l = i + 1, r = N - 1;
            while(l < r)
            {
                int sum = arr[l] + arr[r] + arr[i];
                if(sum < X)
                l++;
                else if(sum > X)
                r--;
                else
                return true;
            }
        }
        return false;
    }
    
};

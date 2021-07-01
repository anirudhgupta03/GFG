//Time Complexity - O(N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=ENcnXXiRT6E
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        
        reverse(arr,arr+d%n);
        
        reverse(arr+d%n,arr+n);
        
        reverse(arr,arr+n);
    }
};

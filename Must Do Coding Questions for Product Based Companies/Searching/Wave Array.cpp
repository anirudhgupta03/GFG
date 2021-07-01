//Method - 1
class Solution{
public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr, int n){
        
        for(int i = 0; i < n - 1; i += 2){
            swap(arr[i],arr[i+1]);
        }
        
    }
};

//Method - 2
//Optimal
class Solution{
public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr, int n){
        
        for(int i = 0; i < n; i+=2){
            
            if(i > 0 && arr[i] < arr[i-1]){
                swap(arr[i],arr[i-1]);
            }
            
            if(i < n - 1 && arr[i] < arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        
    }
};

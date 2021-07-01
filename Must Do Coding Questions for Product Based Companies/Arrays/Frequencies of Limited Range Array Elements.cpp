//Time Complexity - O(NlogN)
//Space Complexity - O(N)
//Ref1: https://www.youtube.com/watch?v=B2hI-QPoisk
//Ref2: https://uploads.disquscdn.com/images/ef4b474b715d308bc2cf8489fac51afbb55d03f773767101d1b18cdd97b0f26a.png
class Solution{   
   public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        sort(arr.begin(),arr.end());
        
        int ind = N;
        
        for(int i = 0; i < N; i++){
            if(arr[i] > N){
                ind = i;
                break;
            }
            arr[i] -= 1;
        }
        
        for(int i = ind; i < N; i++){
            arr[i] = 0;
        }
        
        for(int i = 0; i < ind; i++){
            arr[arr[i]%N] = arr[arr[i]%N] +  N;
        }
        
        for(int i = 0; i < N; i++){
            arr[i] /= N;
        }
    }
};

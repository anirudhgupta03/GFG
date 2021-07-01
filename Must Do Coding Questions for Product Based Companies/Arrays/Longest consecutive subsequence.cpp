//Ref: https://www.youtube.com/watch?v=qgizvmgeyUM
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> us;
        
        for(int i = 0; i < N; i++){
            us.insert(arr[i]);
        }
        
        int maxLen = 1;
        
        for(int i = 0; i < N; i++){
            
            if(us.find(arr[i] - 1) == us.end()){
               int currLen = 1;
               int currNum = arr[i];
               
               while(us.find(currNum + 1) != us.end()){
                   currNum += 1;
                   currLen++;
               }
               
               maxLen = max(maxLen,currLen);
            }
        }
        
        return maxLen;
    }
};

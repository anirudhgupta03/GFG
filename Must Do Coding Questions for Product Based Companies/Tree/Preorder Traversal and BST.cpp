class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        
        stack<int> s;
        
        int root = INT_MIN;
        
        s.push(arr[0]);
        
        for(int i = 1; i < N; i++){
            
            if(arr[i] < root){
                return 0;
            }
            if(arr[i] > s.top()){
                
                while(!s.empty() && arr[i] > s.top()){
                    root = s.top();
                    s.pop();
                }
            }
            s.push(arr[i]);
        }
        
        return 1;
    }
};

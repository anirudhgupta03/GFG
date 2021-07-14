  class Solution{
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        vector<int> res(n);
        
        for(int i = 0; i < n; i++){
            if(i < k - 1){
                res[i] = -1;
                pq.push(arr[i]);
            }
            else{
                pq.push(arr[i]);
                if(pq.size() > k){
                    pq.pop();
                }
                res[i] = pq.top();
            }
        }
        
        return res;
    }
};

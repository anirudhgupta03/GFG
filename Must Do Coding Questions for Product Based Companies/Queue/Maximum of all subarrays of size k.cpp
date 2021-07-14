class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        
        deque<int> dq;
        
        int i = 0, j = 0;
        
        while(j < n){
            
            while(!dq.empty() && dq.back() < arr[j]){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            if(j - i + 1 < k){
                j++;
            }
            else{
                res.push_back(dq.front());
                if(arr[i] == dq.front()){
                    dq.pop_front();
                }
                j++;
                i++;
            }
        }
        return res;
    }
};

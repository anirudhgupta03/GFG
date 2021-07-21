class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> res;
        
        for(int i = 0; i <= n - 4; i++){
            if(i != 0 && arr[i] == arr[i-1]){
                continue;
            }
            for(int j = i + 1; j <= n - 3; j++){
                if(j != i+1 && arr[j] == arr[j-1]){
                    continue;
                }
                int lo = j + 1, hi = n - 1;
                
                while(lo < hi){
                     
                    int sum = arr[i] + arr[j] + arr[lo] + arr[hi];
                    
                    if(sum == k){
                        vector<int> temp = {arr[i],arr[j],arr[lo],arr[hi]};
                        res.push_back(temp);
                        
                        while(lo < hi && arr[lo] == arr[lo+1]) lo++;
                        lo++;
                        while(lo < hi && arr[hi] == arr[hi-1]) hi--;
                        hi--;
                        
                    }
                    else if(sum < k){
                        lo++;
                    }
                    else{
                        hi--;
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

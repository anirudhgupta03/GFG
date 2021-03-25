bool cmp(Job a, Job b){
    
    return a.profit > b.profit;
}
class Solution {
  public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int deadline = INT_MIN;
        
        for(int i = 0; i < n; i++){
            deadline = max(deadline,arr[i].dead);
        }
        
        vector<int> v(deadline,-1);
        
        sort(arr,arr+n,cmp);
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead - 1; j >= 0; j--){
                if(v[j] == -1){
                    v[j] = arr[i].id;
                    sum += arr[i].profit;
                    break;
                }
            }
        }
        vector<int> res;
        int count = 0;
        for(int i = 0; i < deadline; i++){
            if(v[i] != -1){
                count++;
            }
        }
        res.push_back(count);
        res.push_back(sum);
        
        return res;
    } 
};

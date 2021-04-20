class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        vector<long long> ans;
        
        ans.push_back(-1);
        
        stack<long long> s;
        
        s.push(arr[n-1]);
        
        for(int i = n - 2; i >= 0; i--){
            
            if(arr[i] < s.top()){
                ans.push_back(s.top());
                s.push(arr[i]);
            }
            else if(arr[i] >= s.top()){
                
                while(!s.empty() && s.top() <= arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top());
                }
                s.push(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    void solve(stack<int> &s, int k){
        
        if(k == 1){
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        solve(s,k-1);
        s.push(temp);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int k = ceil((sizeOfStack)/2.0);
        k = sizeOfStack - k + 1;
        solve(s,k);
    }
};

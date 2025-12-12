// User function Template for C++
#define ll long long
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        ll mod = 1e5;
        queue<ll> q;
        q.push(start);  
        
        vector<int> vis(100000, 0);
        vis[start] = 1;
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                ll curr = q.front();
                q.pop();
                if(curr == end) return steps;
                for(int &ele: arr){
                    if(vis[(curr*ele)%mod] == 0){
                        q.push((curr*ele)%mod);
                        vis[(curr*ele)%mod] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

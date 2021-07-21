//Ref: https://www.youtube.com/watch?v=X2TufR5vY98&t=158s
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        vector<pair<int,int>> v;
        vector<int> vis(n);
        
        for(int i = 0; i < n; i++){
            if(arr[i] >= k){
                v.push_back({arr[i] - k, i});
            }
            v.push_back({arr[i] + k, i});
        }
        sort(v.begin(),v.end());
        
        int ele = 0, l = 0, r = 0;
        
        while(ele < n && r < v.size()){
            if(vis[v[r].second] == 0){
                ele++;
            }
            vis[v[r].second]++;
            r++;
        }
        
        int ans = v[r-1].first - v[l].first;
        
        while(r < v.size()){
            if(vis[v[l].second] == 1){
                ele--;
            }
            vis[v[l].second]--;
            l++;
            
            while(ele < n && r < v.size()){
                if(vis[v[r].second] == 0){
                    ele++;
                }
                vis[v[r].second]++;
                r++;
            }
            
            if(ele == n){
                ans = min(ans, v[r-1].first - v[l].first);
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};

class Solution {
  public:
    #define ll long long
    void prank(long long a[], int n){
        // code here
        vector<ll> vis(n,0);
        vector<ll> ind(n);
        
        for(int i = 0; i < n; i++){
            ind[a[i]] = i;
        }
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 1 || a[i] == i) continue;
            int ele = -1;
            while(vis[i] == 0){
                int temp = a[i];
                a[i] = ele;
                ele = temp;
                vis[i] = 1;
                i = ind[i];
            }
            a[i] = ele;
        }
    }
};

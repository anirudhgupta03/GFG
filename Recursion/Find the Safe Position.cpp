class Solution {
  public:
  
    int solve(vector<int> &v, int k, int ind){  //vector is passed by reference
        
        if(v.size() == 1){
            return v[0];
        }
        
        ind = (ind + k) % v.size();
        v.erase(v.begin() + ind);
        
        return solve(v,k,ind);
    }
    int safePos(int n, int k) {
        
        k--;
        
        vector<int> v(n);
        
        for(int i = 0; i < n; i++){
            v[i] = i + 1;
        }
        return solve(v,k,0);
    }
};

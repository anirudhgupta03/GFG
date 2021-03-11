class Solution{
public:
    int count = 0;
    void solve(int s,int h,int d,vector<int> &v,int n,int N){
        
        
        if(N == 1){
            count++;
            if(count == n){
                v.push_back(s);
                v.push_back(d);
            }
            return;
        }
        
        solve(s,d,h,v,n,N-1);
        count++;
        if(count == n){
            v.push_back(s);
            v.push_back(d);
        }
        solve(h,s,d,v,n,N-1);
        
        return;
    }
    
    vector<int> shiftPile(int N, int n){
        int s = 1;
        int h = 2;
        int d = 3;
        
        vector<int> v;
        solve(s,h,d,v,n,N);
        return v;
    }
};

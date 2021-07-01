class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long long s = -1, e = -1;
        
        long long lo = 0, hi = v.size() - 1;
        
        
        while(lo <= hi){
            long long mid = (lo + hi)/2;
            if(v[mid] > x){
                hi = mid - 1;
            }
            else if(v[mid] < x){
                lo = mid + 1;
            }
            else{
                e = mid;
                lo = mid + 1;
            }
        }
        pair<long long,long long> p;
        if(e == -1){
            
            p = {-1,-1};
            return p;
        }
        lo = 0, hi = v.size() - 1;
        
        while(lo <= hi){
            long long mid = (lo + hi)/2;
            if(v[mid] > x){
                hi = mid - 1;
            }
            else if(v[mid] < x){
                lo = mid + 1;
            }
            else{
                s = mid;
                hi = mid - 1;
            }
        }
        p = {s,e};
        return p;
    }
};

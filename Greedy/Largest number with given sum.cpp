class Solution{
    public:
    string largestNumber(int n, int sum){
        
        vector<int> v(n,0);
        
        for(int i = 0; i < n; i++){
            
            for(int j = 9; j >= 0; j--){
                
                if(sum >= j){
                    v[i] = j;
                    sum -= j;
                    break;
                }
            }
        }
        
        string p;
        
        if(sum > 0){
            return "-1";
        }
        for(int i = 0; i < n; i++){
            p.push_back(v[i] + '0');
        }
        return p;
    }
};

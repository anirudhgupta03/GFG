class Solution{
{
    public:
        long long findHash(string s, int p){
            
            long long ans = 0;
            
            for(int i = 0; i < s.size(); i++){
                ans += (s[i] - 96)*(pow(p,i));
            }
            
            return ans;
        }
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            
            int n = pat.size();
            int m = txt.size();
            
            if(n > m){
                res.push_back(-1);
                return res;
            }
            
            int p = 101;
            
            long long hash = findHash(pat,p);
          
            long long rollhash = findHash(txt.substr(0,n),p);
            
            int flag = 0;
            
            if(rollhash == hash){
                if(pat == txt.substr(0,pat.size())){
                    res.push_back(1);
                    flag = 1;
                }
            }
            
            
            for(int i = 1; i <= m - n; i++){
                rollhash -= (txt[i-1] - 96);
                rollhash /= 101;
                rollhash += (txt[i+n-1]-96)*pow(101,n-1);
                
                if(rollhash == hash){
                    if(pat == txt.substr(i,n)){
                        res.push_back(i+1);
                        flag = 1;
                    }
                }
            }
            if(flag == 0) res.push_back(-1);
            return res;
        }
     
};

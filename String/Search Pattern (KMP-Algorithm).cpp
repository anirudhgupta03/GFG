class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n = pat.size();
            
            int lps[n];
            
            int j = 0, i = 1;
            
            lps[0] = 0;
            
            while(i < n){
                if(pat[i] == pat[j]){
                    j++;
                    lps[i] = j;
                    i++;
                }
                else{
                    if(j == 0){
                        lps[i] = 0;
                        i++;
                    }
                    else{
                        j = lps[j-1];
                    }
                }
            }
            
            vector<int> res;
            
            i = 0; // index for txt[]
            j = 0; // index for pat[]
            
            int m = txt.size();
            
            while (i < m) {
                if (pat[j] == txt[i]) {
                    j++;
                    i++;
                }
          
                if (j == n) {
                    res.push_back(i - j + 1);
                    j = lps[j - 1];
                }
          
                else if (i < m && pat[j] != txt[i]) {
                    if (j != 0)
                        j = lps[j - 1];
                    else
                        i = i + 1;
                }
            }
            return res;
        }
};

class Solution{
public:
    int longestUniqueSubsttr(string S){
        
        int alpha[26];
        memset(alpha,-1,sizeof(alpha));
        
        int l = 0, r = 0, maxLen = 1;
        
        while(r < S.size()){
            
            if(alpha[S[r] - 'a'] != -1 && alpha[S[r] - 'a'] >= l){
                maxLen = max(maxLen,r-l);
                l = alpha[S[r]-'a'] + 1;
            }
            alpha[S[r] - 'a'] = r;
            r++;
        }
        maxLen = max(maxLen,r-l);
        return maxLen;
    }
};

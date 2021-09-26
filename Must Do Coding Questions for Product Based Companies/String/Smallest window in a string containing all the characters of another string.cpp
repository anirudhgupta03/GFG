//Window String 
class Solution{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int umap[256] = {0};
        
        for(int i = 0; i < p.size(); i++){
            umap[p[i]]++;
        }
        
        int distinct = 0;
        
        for(int i = 0; i < 256; i++){
            if(umap[i] != 0){
                distinct++;
            }
        }
        int count = 0, l = 0, r = 0;
        
        int temp[256] = {0};
        
        int minLen = INT_MAX;
        string res;
        
        while(r < s.size()){
            
            temp[s[r]]++;
            
            if(umap[s[r]] != 0 && temp[s[r]] == umap[s[r]]){
                count++;
            }
            
            if(count == distinct){
                
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }
                
                while(l <= r){
                    
                    temp[s[l]]--;
                    
                    if(umap[s[l]] != 0 && temp[s[l]] < umap[s[l]]){
                        count--;
                        l++;
                        break;
                    }
                    l++;
                    if(r - l + 1 < minLen){
                        minLen = r - l + 1;
                        res = s.substr(l, minLen);
                    }
                }
            }
            r++;
        }
        if(minLen == INT_MAX){
            return "-1";
        }
        return res;
    }
};

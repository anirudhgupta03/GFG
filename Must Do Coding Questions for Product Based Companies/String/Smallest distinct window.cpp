class Solution{
public:
    string findSubString(string str)
    {
        unordered_set<char> us;
        
        for(int i = 0; i < str.size(); i++){
            us.insert(str[i]);
        }
        
        int l = 0, r = 0;
        
        unordered_map<char,int> temp;
        
        int minLen = INT_MAX;
        string ans;
        
        while(r < str.size()){
            
            temp[str[r]]++;
            
            if(temp.size() == us.size()){
                
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    ans = str.substr(l, minLen);
                }
                
                while(l < r){
                    
                    temp[str[l]]--;
                    
                    if(temp[str[l]] == 0){
                        temp.erase(str[l]);
                        l++;
                        break;
                    }
                    
                    l++;
                    if(r - l + 1 < minLen){
                        minLen = r - l + 1;
                        ans = str.substr(l, minLen);
                    }
                }
            }
            r++;
        }
        return ans;
    }
};

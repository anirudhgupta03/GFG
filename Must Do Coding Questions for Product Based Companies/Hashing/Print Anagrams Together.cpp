vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    vector<vector<string>> res;
    
    map<vector<int>,vector<string>> mp;
    
    for(int i = 0; i < string_list.size(); i++){
        
        string temp = string_list[i];
        
        vector<int> alpha(26,0);
        
        for(int j = 0; j < temp.size(); j++){
            alpha[temp[j]-'a']++;
        }
        
        mp[alpha].push_back(temp);
    }
    
    for(auto x: mp){
        res.push_back(x.second);
    }
    
    return res;

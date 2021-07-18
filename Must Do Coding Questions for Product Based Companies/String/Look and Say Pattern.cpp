    public:
    string lookandsay(int n) {
        
        string s = "1";
        
        for(int i = 2; i <= n; i++){
            
            int j = 0, count = 0;
            string temp;
            char ch = s[j];
            while(j < s.size()){
                
                while(j < s.size() && s[j] == ch){
                    count++;
                    j++;
                }
                
                temp += to_string(count);
                temp.push_back(ch);
                ch = s[j];
                count = 0;
            }
            
            s = temp;
        }
        
        return s;
    }   
};

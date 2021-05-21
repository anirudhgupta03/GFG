class Solution{
public:
    string chooseandswap(string a){
        
        set<char> s;
        
        for(int i = 0; i < a.size(); i++){
            s.insert(a[i]);
        }
        
        for(int i = 0; i < a.size(); i++){
            s.erase(a[i]);
            if(s.empty()){
                break;
            }
            
            char ch1 = *s.begin();
            char ch2 = a[i];
            
            if(ch1 < ch2){
                for(int j = 0; j < a.size(); j++){
                    if(a[j] == ch1){
                        a[j] = ch2;
                    }
                    else if(a[j] == ch2){
                        a[j] = ch1;
                    }
                }
                break;
            }
        }
        return a;
    }
};

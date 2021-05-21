class Solution{
public:
    string chooseandswap(string a){
        
        vector<int> left_most(26,-1);
        
        int n = a.size();
        
        for(int i = 0; i < n; i++){
            
            if(left_most[a[i]-97] == -1){
                left_most[a[i]-97] = i;
            }
        }
        
        for(int i = 0; i < n; i++){
           bool flag = false;
           
           for(int j = 0; j < 26; j++){
               
               if(left_most[a[i]-97] < left_most[j] && j < a[i] - 97){
                   
                   char ch1 = a[i];
                   char ch2 = j + 'a';
                   
                   for(int k = 0; k < n; k++){
                       if(a[k] == ch1){
                           a[k] = ch2;
                       }
                       else if(a[k] == ch2){
                           a[k] = ch1;
                       }
                   }
                   flag = true;
                   break;
               }
           }
           if(flag){
               break;
           }
        }
        return a;
    }
    
};

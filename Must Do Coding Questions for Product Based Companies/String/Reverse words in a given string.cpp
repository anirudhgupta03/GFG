class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans;
        
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '.'){
                S[i] = ' ';
            }
        }
        
        stringstream X(S);
        string temp;
        
        while(X >> temp){
            ans = "." + temp + ans;
        }
        ans.erase(ans.begin());
        return ans;
    } 
};

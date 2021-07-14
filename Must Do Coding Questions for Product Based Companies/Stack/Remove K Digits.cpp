class Solution{
    public:
    string removeKdigits(string S, int K) {
        
        int n = S.size();
        stack<char> st;
        
        for(int i = 0; i < S.size(); i++){
            
            while(!st.empty() && K > 0 && st.top() > S[i]){
                st.pop();
                K--;
            }
            
            if(!st.empty() || S[i] != '0'){
                st.push(S[i]);
            }
        }
        
        while(!st.empty() && K--){
            st.pop();
        }
        
        if(st.empty()){
            return "0";
        }
        
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
}
};

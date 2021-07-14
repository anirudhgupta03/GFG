//Ref: https://www.youtube.com/watch?v=mg9yi6YuAVk
class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int prec(char ch){
        
        if(ch == '^'){
            return 3;
        }
        else if(ch == '*' || ch == '/'){
            return 2;
        }
        else if(ch == '+' || ch == '-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    string infixToPostfix(string s)
    {
        string res;
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                res.push_back(s[i]);
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    res.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && prec(st.top()) >= prec(s[i])){
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        
        for(int i = 0; i < x.size(); i++){
            if(x[i] == '(' || x[i] == '{' || x[i] == '['){
                st.push(x[i]);
            }
            else if(x[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(x[i] == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(x[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.size() == 0)
        return true;
        
        return false;
    }

};

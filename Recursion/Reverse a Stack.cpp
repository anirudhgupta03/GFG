class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        
        int ele = st.top();
        st.pop();
        
        reverseStack(st);
        
        stack<int> tst;
        
        while(!st.empty()){
            tst.push(st.top());
            st.pop();
        }
        
        st.push(ele);
        
        while(!tst.empty()){
            st.push(tst.top());
            tst.pop();
        }
    }
};

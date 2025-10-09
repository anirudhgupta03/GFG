class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        
        int ele = st.top();
        st.pop();
        
        sortStack(st);
    
        stack<int> tst;    
        while(!st.empty() && st.top() > ele){
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

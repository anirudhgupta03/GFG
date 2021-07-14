//Ref: https://www.youtube.com/watch?v=CiiXBvrX-5A
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            
            int p1 = st.top();
            st.pop();
            int p2 = st.top();
            st.pop();
            
            if(M[p1][p2] == 0){
                st.push(p1);
            }
            else{
                st.push(p2);
            }
        }
        
        int p = st.top();
        st.pop();
        
        bool flag1 = false, flag2 = false;
        
        for(int i = 0; i < n; i++){
            if(p != i && M[i][p] == 0){
                return -1;
            }
        }
        for(int j = 0; j < n; j++){
            if(M[p][j] == 1){
                return -1;
            }
        }
        return p;
    }
};

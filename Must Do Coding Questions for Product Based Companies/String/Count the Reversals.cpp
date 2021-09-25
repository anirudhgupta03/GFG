//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
int countRev (string s)
{
    if(s.size() % 2 != 0){
        return -1;
    }
    
    stack<char> st;
    
    int c1 = 0, c2 = 0;
    
    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == '{'){
            st.push(s[i]);
            c1++;
        }
        else if(s[i] == '}' && !st.empty()){
            st.pop();
            c1--;
        }
        else{
            c2++;
        }
    }
    return ceil(c1/2.0) + ceil(c2/2.0);
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=dTBpH9YT2HQ
int countRev (string s)
{
    if(s.size() % 2 != 0){
        return -1;
    }
    
    int open = 0, close = 0;
    
    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == '{'){
            open++;
        }
        else if(s[i] == '}' && open == 0){
            close++;
        }
        else{
            open--;
        }
    }
    
    return int(ceil(open/2.0) + ceil(close/2.0));
}

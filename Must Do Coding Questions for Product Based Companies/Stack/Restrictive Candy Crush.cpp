class Solution{
public:
    string Reduced_String(int k,string s){
        
        if(k == 1){
            return "";
        }
        
        stack<pair<int,int>> st;
        
        for(int i = 0; i < s.size(); i++){
            
            if(st.empty()){
                st.push({s[i],1});
            }
            else if(st.top().first == s[i]){
                st.push({s[i],st.top().second+1});
                
                if(st.top().second == k){
                    int x = k;
                    while(x){
                        st.pop();
                        x--;
                    }
                }
            }
            else if(st.top().first!=s[i]){
                st.push({s[i],1});
            }
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }


};

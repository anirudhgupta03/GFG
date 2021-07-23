class Solution{
public:
    struct TrieNode{
      
      TrieNode* child[26];
      vector<int> ind;
      
      TrieNode(){
          for(int i = 0; i < 26; i++){
              child[i] = NULL;
          }
      }
    };
    void add(int ind, TrieNode* root, string s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]-'a'] == NULL){
                root -> child[s[i]-'a'] = new TrieNode();
            }
            root = root -> child[s[i]-'a'];
            root -> ind.push_back(ind);
        }
    }
    void search(TrieNode* root, vector<vector<string>> &res, string contact[], string s){
        
        int i;
        for(i = 0; i < s.size(); i++){
            if(root -> child[s[i] -'a'] != NULL){
                vector<int> index = root -> child[s[i]-'a'] -> ind;
                set<string> st;
                for(int i = 0; i < index.size(); i++){
                    st.insert(contact[index[i]]);
                }
                vector<string> vec;
                for(auto x: st){
                    vec.push_back(x);
                }
                res.push_back(vec);
                root = root -> child[s[i] - 'a'];
            }
            else{
                break;
            }
        }
        vector<string> temp = {"0"};
        while(i < s.size()){
            res.push_back(temp);
            i++;
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode* root = new TrieNode();
        vector<vector<string>> res;
        
        for(int i = 0; i < n; i++){
            add(i,root,contact[i]);
        }
        
        search(root, res, contact, s);
        
        return res;
    }
};

class Solution
{
    public:
    
    struct TrieNode{
      
      TrieNode* child[26];
      int count;
      
      TrieNode(){
          for(int i = 0; i < 26; i++){
              child[i] = NULL;
          }
          count = 0;
      }
    };
    void add(TrieNode* root, string s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]-'a'] == NULL){
                root -> child[s[i]-'a'] = new TrieNode();
            }
            root = root -> child[s[i]-'a'];
            root -> count++;
        }
    }
    string search(TrieNode* root, string s){
        
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]-'a'] -> count != 1){
                ans.push_back(s[i]);
                root = root -> child[s[i]-'a'];
            }
            else{
                ans.push_back(s[i]);
                break;
            }
        }
        return ans;
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        TrieNode* root =  new TrieNode();
        
        for(int i = 0; i < n; i++){
            add(root,arr[i]);
        }
        
        vector<string> res;
        
        for(int i = 0; i < n; i++){
            res.push_back(search(root,arr[i]));
        }
        return res;
    }
    
};

class Solution
{
public:
    struct TrieNode{
      
      TrieNode* child[26];
      bool isLeaf;
      
      TrieNode(){
          for(int i = 0; i < 26; i++){
              child[i] = NULL;
          }
          isLeaf = false;
      }
    };
    void add(TrieNode* root, string s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]-'a'] == NULL){
                root -> child[s[i]-'a'] = new TrieNode();
            }
            root = root -> child[s[i]-'a'];
        }
        root -> isLeaf = true;
    }
    bool search(TrieNode* root, string s){
        
        TrieNode* temp = root;
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]-'a'] == NULL){
                return false;
            }
            root = root -> child[s[i]-'a'];
        }
        if(root -> isLeaf){
            return true;
        }
        return false;
    }
    bool solve(string str, TrieNode *root)
    {
        int size = str.size();

        if (size == 0)  return true;
      
        for (int i=1; i<=size; i++)
        {
            if (search(root, str.substr(0, i)) && solve(str.substr(i, size-i), root))
                return true;
        }

        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < B.size(); i++){
            add(root,B[i]);
        }
        
        return solve(A,root);
    }
};

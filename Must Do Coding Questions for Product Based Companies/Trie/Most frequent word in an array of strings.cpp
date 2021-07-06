class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    struct TrieNode{
      
      int wordend;
      TrieNode* child[26];
      
      TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
            wordend = 0;
        }    
      }
      
    };
    int add(TrieNode* root, string s){
        
        bool flag = true;
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]-'a'] == NULL){
                flag = false;
                root -> child[s[i]-'a'] = new TrieNode();
            }
            root = root -> child[s[i]-'a'];
        }
        if(flag == true){
            root -> wordend++;
        }
        else{
            root -> wordend = 1;
        }
        return root -> wordend;
    }
    string mostFrequentWord(string arr[], int n) 
    {
        string ans;
        int freq = 0;
        
        unordered_map<string,int> umap;
        
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < n; i++){
            int t = add(root,arr[i]);
            umap[arr[i]] = t;
            if(t > freq){
                freq = t;
            }
        }
        
        for(int i = 0; i < n; i++){
            
            if(umap[arr[i]] == freq){
                ans = arr[i];
                umap.erase(arr[i]);
            }
        }
        return ans;
    }
};

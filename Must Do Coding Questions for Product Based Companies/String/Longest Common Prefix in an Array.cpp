class Solution{
public:
    
    struct TrieNode{

        TrieNode* child[26];
        int freq;
        
        TrieNode(){
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
            freq = 0;
        }
    };
    
    void add(TrieNode* root, string s, int idx){
        
        if(idx == s.size()){
            return;
        }
        
        if(root -> child[s[idx]-'a'] == NULL){
            root -> child[s[idx] - 'a'] = new TrieNode();
        }
        root->child[s[idx]-'a']->freq++;
        add(root->child[s[idx]-'a'],s,idx+1);
    }
    
    void findLCP(TrieNode* root, string s, int idx, int &len, int N){
    
        if(idx == s.size() || root->child[s[idx]-'a']->freq != N){
            len = idx;
            return;
        }
        if(root->child[s[idx]-'a'] != NULL){
            return findLCP(root->child[s[idx]-'a'],s,idx+1,len, N);
        }
    }
    string longestCommonPrefix (string arr[], int N)
    {
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < N; i++){
            add(root,arr[i],0);
        }
        
        int len = 0;
        findLCP(root,arr[0],0,len,N);
        
        if(len == 0){
            return "-1";
        }
        return arr[0].substr(0,len);
    }
};

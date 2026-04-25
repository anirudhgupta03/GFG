struct TrieNode{
    TrieNode* child[26];
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};
class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int len = s.length();
        
        TrieNode* head = new TrieNode();
        TrieNode* curr = head;
        
        int count = 0;
        
        for(int i = 0; i < len; i++){
            curr = head;
            for(int j = i; j < len; j++){
                if(curr -> child[s[j] - 'a'] == nullptr){
                    count++;
                    curr -> child[s[j] - 'a'] = new TrieNode();
                }
                curr = curr -> child[s[j] - 'a'];
            }
        }
        return count;
    }
};

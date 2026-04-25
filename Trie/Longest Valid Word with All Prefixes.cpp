class TrieNode{
public:
    TrieNode* child[26];
    bool isWordEnd;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
        isWordEnd = false;
    }
};

class Solution {
public:
    void solve(TrieNode* curr, string& str, string& res){
        
        if(res == "" || str.size() > res.size()){
            res = str;
        }
        
        if(curr == nullptr){
            return;
        }
        
        
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(curr -> child[ch - 'a'] != nullptr && curr -> child[ch - 'a'] -> isWordEnd){
                str.push_back(ch);
                solve(curr -> child[ch - 'a'], str, res);
                str.pop_back();
            }
        }
    }
    string longestValidWord(vector<string>& words) {
        // code here
        int len = words.size();
        
        TrieNode* head = new TrieNode();
        TrieNode* curr;
        
        for(string &s: words){
            curr = head;
            for(char x: s){
                if(curr -> child[x - 'a'] == nullptr){
                    curr -> child[x - 'a'] = new TrieNode();
                }
                curr = curr -> child[x - 'a'];
            }
            curr -> isWordEnd = true;
        }
        
        string str = "", res = "";
        
        solve(head, str, res);
        
        return res;
    }
};

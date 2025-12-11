//Ref: https://www.youtube.com/watch?v=U3N_je7tWAs&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=26
class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int len = words.size();
        unordered_map<char, vector<char>> adj;
        vector<int> indegree(26, 0);
        unordered_set<char> chars;  
        for(auto &w: words){
            for(char &c: w){
                chars.insert(c);
            }
        }
        for(int i = 0; i < len - 1; i++){
            string word1 = words[i], word2 = words[i + 1];
            int l = min(word1.size(), word2.size());
            // abcde abcd (Not a valid case as abcde should come after abcd)
            if(word1.size() > word2.size() && word1.substr(0, l) == word2){
                return "";
            }            
            for(int j = 0; j < l; j++){
                if(word1[j] != word2[j]){
                    adj[word1[j]].push_back(word2[j]);
                    indegree[word2[j] - 'a']++;
                    break;
                }
            }
        }
        string res;
        queue<char> q;
        for(char c: chars){
            if(indegree[c - 'a'] == 0) q.push(c);
        }
        while(!q.empty()){
            char curr = q.front();
            res.push_back(curr);
            q.pop();   
            for(auto &adjNodes: adj[curr]){
                if(--indegree[adjNodes - 'a'] == 0){
                    q.push(adjNodes);
                }
            }
        }
        if(res.size() < chars.size()) return "";
        return res;
    }
};

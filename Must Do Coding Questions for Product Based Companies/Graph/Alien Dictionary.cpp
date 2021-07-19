class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int> al[26];
        vector<int> in(26,0);
        
        for(int i = 1; i < N; i++){
            
            string curr = dict[i], prev = dict[i-1];
            
            if(curr[0] == prev[0]){
                
                int k = 0, j = 0;
                while(k < curr.size() && j < prev.size() && curr[k] == prev[j]){
                    k++;
                    j++;
                }
                
                if(k < curr.size() && j < prev.size()){
                    al[prev[j] - 'a'].push_back(curr[k] - 'a');
                    in[curr[k] - 'a']++;
                }
            }
            else{
                al[prev[0] - 'a'].push_back(curr[0] - 'a');
                in[curr[0] - 'a']++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < 26; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        string res;
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            res.push_back(curr + 'a');
            for(int i = 0; i < al[curr].size(); i++){
                in[al[curr][i]]--;
                
                if(in[al[curr][i]] == 0){
                    q.push(al[curr][i]);
                }
            }
        }
        return res;
    }
};

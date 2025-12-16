// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int> leaf(leaves + 1, 0);
        for(int i = 0; i < N; i++){
            if(leaf[frogs[i]] || frogs[i] > leaves) continue;
            for(int j = frogs[i]; j <= leaves; j += frogs[i]){
                leaf[j] = 1;
            }
        }
        int count = 0;
        for(int i = 1; i <= leaves; i++){
            if(!leaf[i]) count++;
        }
        return count;
    }
};

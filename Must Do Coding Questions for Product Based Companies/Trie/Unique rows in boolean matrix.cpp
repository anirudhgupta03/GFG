/*You are required to complete this function*/
struct TrieNode{
  
  TrieNode* child[2];
  int count = 0;
  
  TrieNode(){
        child[0] = child[1] = NULL;
  }
};

void add(TrieNode* root, vector<int> v, bool &flag){
    
    for(int i = 0; i < v.size(); i++){
        if(root -> child[v[i]] == NULL){
            root -> child[v[i]] = new TrieNode();
        }
        root = root -> child[v[i]];
    }
    root -> count++;
    if(root ->count == 1){
        flag = true;
    }
}

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    TrieNode* root = new TrieNode();
    vector<vector<int>> res;
    
    for(int i = 0; i < row; i++){
        bool flag = false;
        vector<int> v;
        for(int j = 0; j < col; j++){
            v.push_back(M[i][j]);
        }
        add(root,v,flag);
        if(flag){
            res.push_back(v);
        }
    }
    
    return res;
}

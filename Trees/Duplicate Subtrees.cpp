/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree
string solve(Node* root, unordered_map<string,int> &umap, vector<Node*> &res){
    
    if(root == NULL){
        return "$";
    }
    
    string s = "";
    s += to_string(root -> data);
    s.push_back(' ');
    s += solve(root ->left, umap, res);
    s.push_back(' ');
    s += solve(root -> right, umap, res);
    
    umap[s]++;
    if(umap[s] == 2){
        res.push_back(root);
    }
    return s;
}
vector<Node*> printAllDups(Node* root)
{
    unordered_map<string,int> umap;
    vector<Node*> res;
    solve(root,umap,res);
    return res;
}

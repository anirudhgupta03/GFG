//Method - 1
void solve(Node* root, int node, vector<int> &path, vector<int> &res){
    
    if(root == NULL){
        return;
    }
        
    if(root -> data == node){
        path.push_back(root->data);
        res = path;
        path.pop_back();
        return;
    }
    
    path.push_back(root -> data);
    solve(root -> left, node, path, res);
    solve(root -> right, node, path, res);
    path.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> path, res;
    
    solve(root,node,path,res);
    
    int n = res.size();
    
    if(n - k - 1 >= 0){
        return res[n-k-1];
    }
    return -1;
}

//Method - 2
//Optimal
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* solve(Node* root, int node, int &k, Node* &anc){
    
    if(root == NULL){
        return NULL;
    }
    
    if(root -> data == node || solve(root -> left,node,k,anc) || solve(root->right,node,k,anc)){
        
        if(k > 0){
            k--;
        }
        else if(k == 0){
            anc = root;
            return NULL;
        }
        
        return root;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    Node *anc = NULL;
    solve(root,node,k,anc);
    
    if(anc) return anc->data;
    return -1;
}

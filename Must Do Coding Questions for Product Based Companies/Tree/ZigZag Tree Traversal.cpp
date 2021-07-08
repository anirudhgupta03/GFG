//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
    vector<int> res;
    
    if(root == NULL){
        return res;
    }
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    
    while(!q.empty()){
        int sz = q.size();
        vector<int> temp;
        while(sz--){
            
            Node* curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            
        }
        if(flag){
            reverse(temp.begin(),temp.end());
        }
        for(int i = 0; i < temp.size(); i++){
            res.push_back(temp[i]);
        }
        flag = !flag;
    }
    
    return res;
}

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> res;
    if(root == NULL){
        return res;
    }
    queue<Node*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        
        int sz = q.size();
        vector<int> temp;
        while(sz--){
            
            Node* curr = q.front();
            q.pop();
            
            temp.push_back(curr -> data);
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
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

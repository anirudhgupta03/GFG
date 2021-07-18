// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
vector<int> postOrder(Node* node) {
    
    vector<int> res;
    
    stack<Node*> s1, s2;
    
    s1.push(node);
    
    while(!s1.empty()){
        
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        
        if(curr -> left) s1.push(curr -> left);
        if(curr -> right) s1.push(curr -> right);
    }
    
    while(!s2.empty()){
        res.push_back(s2.top() -> data);
        s2.pop();
    }
    
    return res;
}

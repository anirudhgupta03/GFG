//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/

vector<int> preOrder(Node* root)
{
    stack<Node*> st;
    
    st.push(root);
    
    vector<int> res;
    
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        res.push_back(curr -> data);
        if(curr -> right) st.push(curr -> right);
        if(curr -> left) st.push(curr -> left);
    }
    
    return res;
}

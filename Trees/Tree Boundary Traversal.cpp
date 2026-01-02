/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL) return res;
        if(root -> left == NULL && root -> right == NULL) return {root -> data};
        
        res.push_back(root -> data);

        //Left Boundary excluding Leaf Nodes
        Node* temp = root -> left;
        while(temp){
            if(temp -> left || temp -> right){
                res.push_back(temp -> data);
            }
            if(temp -> left == NULL) temp = temp -> right;
            else temp = temp -> left;
        }

        //Leaf Nodes
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            if(curr -> left == NULL && curr -> right == NULL){
                res.push_back(curr -> data);
            }
            if(curr -> right) st.push(curr -> right);
            if(curr -> left) st.push(curr -> left);
        }

        //Reverse Right Boundary exculding Leaf Nodes
        temp = root -> right;
        while(temp){
            if(temp -> left || temp -> right){
                st.push(temp);
            }
            if(temp -> right == NULL) temp = temp -> left;
            else temp = temp -> right;
        }
        
        while(!st.empty()){
            res.push_back(st.top() -> data);
            st.pop();
        }
        return res;
    }
};

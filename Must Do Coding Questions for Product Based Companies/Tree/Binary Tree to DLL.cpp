struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void solve(Node* root, Node* &head, Node* &prev, int &f){
        
        if(root == NULL){
            return;
        }
        
        solve(root -> left, head, prev, f);
        if(f == 0){
            head = root;
            prev = root;
            f = 1;
        }
        else{
            prev -> right = root;
            root -> left = prev;
            prev = root;
        }
        solve(root -> right, head, prev, f);
    }
    Node * bToDLL(Node *root)
    {
        Node* head = NULL;
        Node* prev = NULL;
        int f = 0;
        solve(root,head,prev,f);
        return head;
    }
};


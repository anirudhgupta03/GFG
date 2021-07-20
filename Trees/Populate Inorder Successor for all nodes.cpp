//Ref: https://www.youtube.com/watch?v=W25l6evkk_U
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node* root, Node* &pre){
        
        if(root == NULL){
            return;
        }
        
        solve(root -> left, pre);
        
        if(pre != NULL){
            pre -> next = root;
        }
        pre = root;
        
        solve(root -> right, pre);
    }
    void populateNext(Node *root)
    {
        Node* pre = NULL;
        solve(root, pre);
    }
};

class Solution {
public:
    void solve(Node* &pre, Node* curr, Node* &first, Node* &second){
        
        if(curr == NULL){
            return;
        }
        
        solve(pre,curr -> left,first,second);
        
        if(first == NULL && pre != NULL && curr -> data < pre -> data){
            first = pre;
        }
        if(first != NULL &&  pre != NULL && curr -> data < pre -> data){
            second = curr;
        }
        pre = curr;
        solve(pre,curr -> right,first,second);
    }
    void correctBST( struct Node* root )
    {
        Node* first = NULL, *second = NULL, *pre = NULL;
        solve(pre,root,first,second);
        
        //cout << first->data << " " << second->data << endl;
        swap(first->data,second->data);
    }
};

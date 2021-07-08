class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        stack<Node*> left, right;
        
        Node* temp = root;
        while(temp){
            left.push(temp);
            temp = temp -> left;
        }
        
        temp = root;
        
        while(temp){
            right.push(temp);
            temp = temp -> right;
        }
        
        while(!left.empty() && !right.empty()){
            
            Node* ltop = left.top(), *rtop = right.top();
            
            if(ltop->data + rtop->data == target){
                return 1;
            }
            else if(ltop->data + rtop->data < target){
                left.pop();
                ltop = ltop -> right;
                while(ltop){
                    left.push(ltop);
                    ltop = ltop->left;
                }
            }
            else{
                right.pop();
                rtop = rtop -> left;
                while(rtop){
                    right.push(rtop);
                    rtop = rtop->right;
                }
            }
        }
        
        return 0;
    }
};

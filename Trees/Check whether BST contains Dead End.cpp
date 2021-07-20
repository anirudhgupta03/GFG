/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void check(int minVal, int maxVal, Node* root, bool &flag){
    
    if(root == NULL){
        return;
    }
    
    if(root -> data == minVal + 1 && root -> data == maxVal - 1){
        flag = true;
        return;
    }
    
    check(minVal, root -> data, root -> left, flag);
    check(root -> data, maxVal, root -> right, flag);
}
bool isDeadEnd(Node *root)
{
    int minVal = 0, maxVal = INT_MAX;
    
    bool flag = false;
    check(minVal, maxVal, root, flag);
    return flag;
}

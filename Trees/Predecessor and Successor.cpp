//Ref: https://www.youtube.com/watch?v=lQIXz5NJYLs
/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
Node* inpre(Node* root){
    
    Node* pre;
    root = root -> left;
    while(root){
        pre = root;
        root = root -> right;
    }
    return pre;
}
Node* insuc(Node* root){
    
    Node* suc;
    root = root -> right;
    while(root){
        suc = root;
        root = root -> left;
    }
    return suc;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL){
        return;
    }
    
    if(root -> key == key){
        
        if(root -> left){
            pre = inpre(root);
        }
        if(root -> right){
            suc = insuc(root);
        }
        return;
    }
    else if(root -> key > key){
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
    else{
        pre = root;
        findPreSuc(root -> right, pre, suc, key);
    }
}

//Alter
/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void find(Node* root, Node* &pre, Node* &suc, int key, Node* &head){
    
    while(root){
        if(root -> key < key){
            pre = root;
            root = root -> right;
        }
        else if(root -> key > key){
            suc = root;
            root = root -> left;
        }
        else{
            head = root;
            return;
        }
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node *head = NULL;
    
    find(root, pre, suc, key, head);
    
    if(head == NULL){
        return;
    }
    Node* temp = head;
    
    if(temp -> right){
        temp = temp -> right;
        while(temp){
            suc = temp;
            temp = temp -> left;
        }
    }
    temp = head;
    if(temp -> left){
        temp = temp -> left;
        while(temp){
            pre = temp;
            temp = temp -> right;
        }
    }   
}

Node* insert(Node* root, int key)
{
    while(1){
        
        if(root -> data < key){
            if(root -> right){
                root = root -> right;
            }
            else{
                root -> right = new Node(key);
                break;
            }
        }
        else if(root -> data > key){
            
            if(root -> left){
                root = root -> left;
            }
            else{
                root -> left = new Node(key);
                break;
            }
        }
        else if(root -> data == key){
            break;
        }
    }
    
    return root;
}


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* n1, Node* n2){
    
    if(n1 == NULL && n2 == NULL){
        return NULL;
    }
    if(n1 == NULL){
        return n2;
    }
    if(n2 == NULL){
        return n1;
    }
    
    Node* head, *prev = NULL;
    
    while(n1 && n2){
        
        if(n1 -> data < n2 -> data){
            if(prev == NULL){
                head = n1;
            }
            else{
                prev -> bottom = n1;
            }
            prev = n1;
            n1 = n1 -> bottom;
        }
        else{
            if(prev == NULL){
                head = n2;
            }
            else{
                prev -> bottom = n2;
            }
            prev = n2;
            n2 = n2 -> bottom;
        }
    }
    if(n1){
        prev -> bottom = n1;
    }
    if(n2){
        prev -> bottom = n2;
    }
    
    return head;
}
Node *flatten(Node *root)
{
   if(root == NULL || root -> next == NULL){
       return root;
   }
   
   Node* temp1 = root, *temp2 = root -> next;
   
   temp1 = merge(temp1,temp2);
  
   root = root -> next -> next;
  
   while(root){
       temp2 = root;
       root = root -> next;
       temp1 = merge(temp1,temp2);
   }
   
   return temp1;
}

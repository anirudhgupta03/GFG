/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1 == NULL && head2 == NULL){
        return NULL;
    }
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    
    Node* prev = NULL, *head;
    
    while(head1 && head2){
        
        if(head1 -> data < head2 -> data){
            
            if(prev == NULL){
                head = head1;
                prev = head;
            }
            else{
                prev -> next = head1;
                prev = head1;
            }
            head1 = head1 -> next;
        }
        else{
            
            if(prev == NULL){
                head = head2;
                prev = head;
            }
            else{
                prev -> next = head2;
                prev = head2;
            }
            head2 = head2 -> next;
        }
    }
    
    if(head1){
        prev -> next = head1;
    }
    if(head2){
        prev -> next = head2;
    }
    return head;
}  

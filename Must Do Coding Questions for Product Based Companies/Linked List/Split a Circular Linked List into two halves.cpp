/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* temp = head, *pre;
    int len = 0;
    
    do{
        pre = temp;
        len++;
        temp = temp -> next;
    }while(temp != head);
    
    pre -> next = NULL;
    
    temp = head;
    int count = 0;
    while(count != (len+1)/2){
        pre = temp;
        temp = temp -> next;
        count++;
    }
    pre -> next = head;
    *head1_ref = head;
    
    Node* temp1 = temp;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = temp1;
    *head2_ref = temp1;
}

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   Node* slow = head, *fast = head;
   
   if(fast == NULL || fast -> next == NULL){
       return false;
   }
   
   do{
       slow = slow -> next;
       fast = fast -> next -> next;
   }while(slow != fast && fast && fast -> next);
   
   if(fast == NULL || fast -> next == NULL){
       return false;
   }
   return true;
}

struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* l1, Node* l2){
        
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        Node* prev = NULL, *head;
        
        while(l1 && l2){
            
            if(l1 -> data < l2 -> data){
                if(prev == NULL){
                    head = l1;
                    prev = l1;
                }
                else{
                    prev -> next = l1;
                    prev = l1;
                }
                l1 = l1 -> next;
            }
            else{
                if(prev == NULL){
                    head = l2;
                    prev = l2;
                }
                else{
                    prev -> next = l2;
                    prev = l2;
                }
                l2 = l2 -> next;
            }
        }
        if(l1){
            prev -> next = l1;
        }
        if(l2){
            prev -> next = l2;
        }
        return head;
    }
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* slow = head, *fast = head, *prev = NULL;
        
        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = NULL;
        
        return merge(mergeSort(head), mergeSort(slow));
    }
};

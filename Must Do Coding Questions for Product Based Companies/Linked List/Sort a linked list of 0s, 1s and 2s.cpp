/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* root = new Node(-1);
        Node* ptr1 = root, *ptr2 = root, *ptr3 = root;
        Node* ptr = head;
        
        while(ptr != NULL){
            if(ptr -> data == 0){
                Node* nextNode1 = ptr -> next;
                Node* nextNode2 = ptr1 -> next;
                ptr1 -> next = ptr;
                ptr -> next = nextNode2;
                ptr = nextNode1;
                ptr1 = ptr1 -> next;
            }
            else if(ptr -> data == 1){
                Node* nextNode1 = ptr -> next;
                Node* nextNode2;
                if(ptr2 == root){
                    nextNode2 = ptr1 -> next;
                    ptr1 -> next = ptr;
                    ptr -> next = nextNode2;
                    ptr2 = ptr;
                    ptr = nextNode1;
                }
                else{
                    nextNode2 = ptr2 -> next;
                    ptr2 -> next = ptr;
                    ptr -> next = nextNode2;
                    ptr = nextNode1;
                    ptr2 = ptr2 -> next;
                }
            }
            else if(ptr -> data == 2){
                Node* nextNode1 = ptr -> next;
                Node* nextNode2;
                if(ptr3 == root){
                    if(ptr2 != root){
                        nextNode2 = ptr2 -> next;
                        ptr2 -> next = ptr;
                        ptr -> next = nextNode2;
                        ptr3 = ptr;
                        ptr = nextNode1;
                    }
                    else{
                        nextNode2 = ptr1 -> next;
                        ptr1 -> next = ptr;
                        ptr -> next = nextNode2;
                        ptr3 = ptr;
                        ptr = nextNode1;
                    }
                }
                else{
                    nextNode2 = ptr3 -> next;
                    ptr3 -> next = ptr;
                    ptr -> next = nextNode2;
                    ptr = nextNode1;
                    ptr3 = ptr3 -> next;
                }
            }
        }
        return root -> next;
    }
};

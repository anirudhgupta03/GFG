//Ref: https://www.youtube.com/watch?v=gRII7LhdJWc&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=8

//Brute Force Solution
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
        if(head == NULL || head -> next == NULL) return head;
      
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);
        Node* dummy3 = new Node(-1);
        
        Node* ptr1 = dummy1, *ptr2 = dummy2, *ptr3 = dummy3;
        
        Node* ptr = head;
        
        while(ptr != NULL){
            Node* nextNode = ptr -> next;
            if(ptr -> data == 0){
                ptr1 -> next = ptr;
                ptr -> next = NULL;
                ptr1 = ptr;
            }
            else if(ptr -> data == 1){
                ptr2 -> next = ptr;
                ptr -> next = NULL;
                ptr2 = ptr;
            }
            else{
                ptr3 -> next = ptr;
                ptr -> next = NULL;
                ptr3 = ptr;
            }
            ptr = nextNode;
        }
        
        Node* dummyNode = new Node(-1);
        head = dummyNode;
        if(dummy1 -> next){
            dummyNode -> next = dummy1 -> next;
            dummyNode = ptr1;
        }
        if(dummy2 -> next){
            dummyNode -> next = dummy2 -> next;
            dummyNode = ptr2;
        }
        if(dummy3 -> next){
            dummyNode -> next = dummy3 -> next;
            dummyNode = ptr3;
        }
        return head -> next;
    }
};

//Optimal Solution
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

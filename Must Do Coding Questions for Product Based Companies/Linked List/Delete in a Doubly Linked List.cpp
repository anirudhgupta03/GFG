/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if(x == 1){
            Node* ptr = head;
            ptr = ptr -> next;
            head -> next = NULL;
            ptr -> prev = NULL;
            delete head;
            return ptr;
        }
        Node* pre = NULL, *ptr = head;
        while(x != 1){
            pre = ptr;
            ptr = ptr -> next;
            x--;
        }
        pre -> next = ptr -> next;
        if(ptr -> next != NULL){
            ptr -> next -> prev = pre;
        }
        ptr -> prev = NULL;
        ptr -> next = NULL;
        delete ptr;
        return head;
    }
};

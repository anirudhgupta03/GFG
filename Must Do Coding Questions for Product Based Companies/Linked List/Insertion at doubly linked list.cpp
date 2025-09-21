/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* pre = NULL, *ptr = head;
        while(p >= 0){
            pre = ptr;
            ptr = ptr -> next;
            p--;
        }
        Node* val = new Node(x);
        val -> prev = pre;
        val -> next = ptr;
        if(ptr != NULL){
            ptr -> prev = val;
        }
        pre -> next = val;
        return head;
    }
};

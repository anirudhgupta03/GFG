/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head == NULL){
            return new Node(x);
        }
        Node* ptr = head;
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
        ptr -> next = new Node(x);
        return head;
    }
};

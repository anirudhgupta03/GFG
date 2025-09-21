/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        if(head == NULL){
            return false;
        }
        Node* ptr = head;
        while(ptr != NULL){
            if(ptr -> data == key){
                return true;
            }
            ptr = ptr -> next;
        }
        return false;
    }
};

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        if(head == NULL){
            return 0;
        }
        Node* ptr = head;
        int count = 0;
        while(ptr){
            count++;
            ptr = ptr -> next;
        }
        return count;
    }
};

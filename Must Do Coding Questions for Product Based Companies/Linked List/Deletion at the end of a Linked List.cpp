//Ref: https://www.youtube.com/watch?v=VaECK03Dz-g&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=3
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        // code here
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        Node* ptr = head;
        while(ptr -> next -> next != NULL){
            ptr = ptr -> next;
        }
        delete ptr->next;
        ptr -> next = NULL;
        return head;
    }
};

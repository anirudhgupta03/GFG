/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        if(head == NULL){
            return NULL;
        }
        if(x == 1){
            Node* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        
        Node* prevNode = NULL, *currNode = head;
        
        while(currNode != NULL){
            prevNode = currNode;
            currNode = currNode -> next;
            x--;
            if(x == 1){
                prevNode -> next = currNode -> next;
                delete currNode;
                break;
            }
        }
        return head;
    }
};

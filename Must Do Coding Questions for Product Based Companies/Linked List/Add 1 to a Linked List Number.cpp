/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseLL(Node* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        Node* prevNode = NULL, *currNode = head, *nextNode = head -> next;
        while(nextNode != NULL){
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode -> next;
        }
        currNode -> next = prevNode;
        return currNode;
    }
    Node* addOne(Node* head) {
        head = reverseLL(head);
        Node* ptr = head, *pre = NULL;
        int carry = 1;
        while(ptr != NULL){
            int sum = ptr -> data + carry;
            ptr -> data = sum % 10;
            carry = sum/10;
            pre = ptr;
            ptr = ptr -> next;
        }
        if(carry) pre -> next = new Node(carry);
        return reverseLL(head);
    }
};

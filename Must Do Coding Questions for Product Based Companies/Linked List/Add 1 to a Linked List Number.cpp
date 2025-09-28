//Method - 1 (Iterative)
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
            if(carry == 0) break;
            pre = ptr;
            ptr = ptr -> next;
        }
        if(carry) pre -> next = new Node(carry);
        return reverseLL(head);
    }
};

//Method - 2 (Recursive)
class Solution {
  public:
    int solve(Node* head){
        if(head == NULL){
            return 1;
        }
        int carry = solve(head -> next);
        if(carry == 0) return 0;
        int sum = carry + head -> data;
        head -> data = sum % 10;
        return sum/10;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry = solve(head);
        if(carry){
            Node* root = new Node(carry);
            root -> next = head;
            head = root;
        }
        return head;
    }
};

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
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL || head -> next == NULL){
            return 0;
        }
        
        Node* slow = head, *fast = head;
        do{
            slow = slow -> next;
            fast = fast -> next -> next;
        }while(fast && fast -> next && slow != fast);
        
        if(fast == NULL || fast -> next == NULL){
            return 0;
        }
        
        Node* ptr = slow;
        int count = 0;
        do{
            count++;
            ptr = ptr -> next;
        }while(ptr != slow);
        
        return count;
    }
};

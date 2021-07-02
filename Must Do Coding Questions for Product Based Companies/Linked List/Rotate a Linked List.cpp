struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* ptr1 = head, *ptr2 = head, *prev = NULL;
        
        while(ptr1 -> next != NULL){
            ptr1 = ptr1 -> next;
        }
        
        while(k){
            ptr1 -> next = ptr2;
            ptr1 = ptr2;
            prev = ptr2;
            ptr2 = ptr2 -> next;
            k--;
        }
        prev -> next = NULL;
        return ptr2;
    }
};

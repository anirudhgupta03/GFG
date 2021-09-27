/*
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(head == NULL){
            return false;
        }
        
        Node* slow = head, *fast = head;
        
        if(fast -> next == NULL){
            return false;
        }
        
        do{
            slow = slow -> next;
            fast = fast -> next -> next;
        }while(slow != fast &&  fast && fast -> next);
        
        if(fast == NULL || fast -> next == NULL){
            return false;
        }
        return true;
    }
};

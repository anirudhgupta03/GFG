class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == NULL){
            return;
        }
        Node* slow = head, *fast = head, *prev = NULL;
        
        do{
            slow = slow -> next;
            if(fast != NULL && fast -> next != NULL){
                prev = fast -> next;
                fast = fast -> next -> next;
            }
            else{
                return;
            }
        }while(slow != fast);
        
        slow = head;
        
        while(slow != fast){
            slow = slow -> next;
            prev = fast;
            fast = fast -> next;
        }
        prev -> next = NULL;
    }
};

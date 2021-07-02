class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* temp1 = NULL, *temp2 = head, *temp3 = head -> next;
        
        while(temp3){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
        
        temp2 -> next = temp1;
        return temp2;
    }
    
};

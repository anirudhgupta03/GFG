/*  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL || head -> next == NULL || k == 1){
            return head;
        }
        
        node *temp = head, *prev = NULL, *start;
        
        while(1){
            
            start = temp;
            
            node* temp1 = NULL, *temp2 = temp, *temp3 = temp -> next;
            
            int count = k;
            
            while(temp3 != NULL && count > 1){
                temp2 -> next = temp1;
                temp1 = temp2;
                temp2 = temp3;
                temp3 = temp3 -> next;
                count--;
            }
            temp2 -> next = temp1;
            
            temp = temp3;
            
            if(prev == NULL){
                head = temp2;
            }
            else{
                prev -> next = temp2;
            }
            prev = start;
            
            if(temp3 == NULL){
                break;
            }
        }
        
        return head;
    }
};

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

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       if(head == NULL || head -> next == NULL || head -> next -> next == NULL){
           return;
       }
       Node* s1 = head, *s2 = head -> next;
       
       Node* temp1 = head, *temp2 = head -> next;
       
       head = head -> next -> next;
       
       int count = 0;
       
       while(head){
           if(count % 2 == 0){
               temp1 -> next = head;
               temp1 = temp1 -> next;
           }
           else{
               temp2 -> next = head;
               temp2 = temp2 -> next;
           }
           head = head -> next;
           count++;
       }
       temp2 -> next = NULL;
       temp1 -> next = s2;
    }
};

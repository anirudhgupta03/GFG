/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
Node* reverseDLL(Node * head)
{
    if(head -> next == NULL){
        return head;
    }
    
    Node* temp1 = NULL, *temp2 = head, *temp3 = head -> next;
    
    while(temp3){
        temp2 -> next = temp1;
        temp2 -> prev = temp3;
        
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
    }
    temp2 -> next = temp1;
    temp2 -> prev = temp3;
    return temp2;
}

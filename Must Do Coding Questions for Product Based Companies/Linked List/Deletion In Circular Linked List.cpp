Node* deleteNode(Node* head, int key) 
{
    if(head ==  NULL || head -> next == head && key == head -> data){
        return NULL;
    }
    Node* pre, *temp = head;
    
    do{
        pre = temp;
        temp = temp -> next;
        if(temp -> data == key){
            if(temp == head){
                head = temp -> next;
            }
            pre -> next = temp -> next;
            temp -> next = NULL;
            break;
        }
    }while(temp != head);
    return head;
}

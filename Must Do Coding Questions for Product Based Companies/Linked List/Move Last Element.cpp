//https://www.codingninjas.com/codestudio/problems/let-last-be-the-first_920455?leftPanelTab=0
/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/
LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {
    
    if(head -> next == NULL){
        return head;
    }
    LinkedListNode<int>* start = head, *temp = head, *pre;
    
    while(temp -> next != NULL){
        pre = temp;
        temp = temp -> next;
    }
    
    pre -> next = NULL;
    temp -> next = head;
    head = temp;
    return head;
}

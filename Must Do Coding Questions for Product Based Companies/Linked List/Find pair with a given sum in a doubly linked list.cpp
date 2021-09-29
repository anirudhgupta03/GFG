/****************************************************************
    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };
*****************************************************************/
bool findPair(Node* head, int k)
{
    Node* lo = head, *hi = head;
    int len = 0;
    
    while(hi -> next != NULL){
        len++;
        hi = hi -> next;
    }
    len++;
  
    int low = 0, high = len - 1;
    while(low < high){
        
        int sum = lo -> data + hi -> data;
        
        if(sum == k){
            return true;
        }
        else if(sum > k){
            hi = hi -> prev;
            high--;
        }
        else{
            lo = lo -> next;
            low++;
        }
    }
    return false;
}

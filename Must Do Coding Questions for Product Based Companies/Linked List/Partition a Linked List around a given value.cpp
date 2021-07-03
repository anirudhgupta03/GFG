// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    
    Node* temp1 = new Node(0);
    Node* temp2 = new Node(0);
    Node* temp3 = new Node(0);
    
    Node* s1 = temp1, *s2 = temp2, *s3 = temp3;
    
    while(head){
        
        if(head -> data < x){
            temp1 -> next = head;
            head = head -> next;
            temp1 = temp1 -> next;
        }
        else if(head -> data == x){
            temp2 -> next = head;
            head = head -> next;
            temp2 = temp2 ->next;
        }
        else{
            temp3 -> next = head;
            head = head -> next;
            temp3 = temp3 ->next;
        }
    }
    temp2 -> next = s3 -> next;
    temp1 -> next = s2 -> next;
    temp3 -> next = NULL;
    return s1 -> next;
}

//Ref1: https://www.youtube.com/watch?v=VNf6VynfpdM&t=8s
//Ref2: https://github.com/striver79/SDESheet/blob/main/cloneLinkedListCPP
/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

//Function to clone a linked list with next and random pointer.
Node *copyList(Node *head) {
    
    Node *iter = head, *front = head;
    
    while(iter){
        front = iter -> next;
        
        Node* copy = new Node(iter -> data);
        iter -> next = copy;
        copy -> next = front;
        
        iter = front;
    }
    
    iter = head;
    while(iter != NULL){
        if(iter -> arb != NULL){
            iter -> next -> arb = iter -> arb -> next;
        }
        iter = iter -> next -> next;
    }
    
    Node *pseudoHead = new Node(0);
    Node* copy = pseudoHead;
    iter = head;
    
    while(iter != NULL){
        
        front = iter -> next -> next;
        
        copy -> next = iter -> next;
        
        iter -> next = front;
        
        copy = copy -> next;
        
        iter = front;
    }
    
    return pseudoHead -> next;
}

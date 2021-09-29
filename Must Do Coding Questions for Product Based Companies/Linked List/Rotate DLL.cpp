//https://www.codingninjas.com/codestudio/problems/rotate-dll_1115782?leftPanelTab=0
/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}
*****************************************************/
DLLNode* rotateDLL(DLLNode* head, int k) 
{
    DLLNode* first = head, *last = head;
    int N = 0;
    
    while(last -> next){
        N++;
        last = last -> next;
    }
    N++;
	  k %= N;
    
    if(k == 0){
        return head;
    }
    
    last -> next = head;
    head -> prev = last;
    
    DLLNode* temp = head, *pre;
    int count = 0;
    
    while(count != k){
        pre = temp;
        temp = temp -> next;
        count++;
    }
    
    head = temp;
    pre -> next = NULL;
    temp -> prev = NULL;
    return head;
}

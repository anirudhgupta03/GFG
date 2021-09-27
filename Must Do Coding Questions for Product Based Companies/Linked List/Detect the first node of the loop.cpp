//https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628?leftPanelTab=0
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
	Node* slow = head, *fast = head;
    
    if(fast == NULL){
        return NULL;
    }
    
    if(fast -> next == NULL){
        return NULL;
    }
    
    do{
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(slow != fast && fast && fast -> next);
    
    if(fast == NULL || fast -> next == NULL){
        return NULL;
    }
    
    slow = head;
    
    while(slow != fast){
    	slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

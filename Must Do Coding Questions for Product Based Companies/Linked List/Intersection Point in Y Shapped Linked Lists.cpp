/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL){
        return -1;
    }
    
    int len1 = 0, len2 = 0;
    
    Node* temp1 = head1, *temp2 = head2;
    
    while(temp1){
        len1++;
        temp1 = temp1 -> next;
    }
    
    while(temp2){
        len2++;
        temp2 = temp2 -> next;
    }
    
    temp1 = head1,  temp2 = head2;
    
    if(len1 > len2){
        while(len1 != len2){
            temp1 = temp1 -> next;
            len1--;
        }
    }
    else if(len2 > len1){
        while(len1 != len2){
            temp2 = temp2 -> next;
            len2--;
        }
    }
    
    while(temp1 != temp2){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    
    if(temp1){
        return temp1 -> data;
    }
    return -1;
}

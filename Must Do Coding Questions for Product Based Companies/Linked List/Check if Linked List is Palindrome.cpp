struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseLL(Node* temp){
        
        if(temp == NULL || temp -> next == NULL){
            return temp;
        }
        
        Node* temp1 = NULL, *temp2 = temp, *temp3 = temp -> next;
        
        while(temp3){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
        temp2 -> next = temp1;
        return temp2;
    }
    bool isPalindrome(Node *head)
    {
        if(head -> next == NULL){
            return true;
        }
        int len = 0;
        
        Node *temp = head;
        
        while(temp){
            len++;
            temp = temp -> next;
        }
        
        len /= 2;
        
        temp = head;
        Node* prev = NULL;
        
        while(len){
            prev = temp;
            temp = temp -> next;
            len--;
        }
        
        prev -> next = NULL;
        
        temp = reverseLL(temp);
        
        while(head && temp){
            
            if(head -> data != temp -> data){
                return false;
            }
            head = head -> next;
            temp = temp -> next;
        }
        return true;
    }
};

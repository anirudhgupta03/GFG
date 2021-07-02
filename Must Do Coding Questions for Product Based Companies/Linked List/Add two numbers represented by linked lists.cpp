struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverseLL(struct Node* head){
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        Node* temp1 = NULL, *temp2 = head, *temp3 = head -> next;
        
        while(temp3){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
        temp2 -> next = temp1;
        return temp2;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first == NULL && second == NULL){
            return NULL;
        }
        if(first == NULL){
            return second;
        }
        if(second == NULL){
            return first;
        }
        
        int len1 = 0, len2 = 0;
        struct Node* temp1 = first, *temp2 = second;
        
        while(temp1){
            len1++;
            temp1 = temp1 -> next;
        }
        
        while(temp2){
            len2++;
            temp2 = temp2 -> next;
        }
        
        if(len2 > len1){
            swap(first,second);
        }
        
        first = reverseLL(first);
        second = reverseLL(second);
        
        temp1 = first, temp2 = second;
        
        Node* prev = NULL;
        
        int carry = 0;
        
        while(temp2){
            int t = temp1 -> data + temp2 -> data + carry;
            temp1 -> data = t%10;
            carry = t/10;
            prev = temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        while(temp1){
            int t = temp1 -> data + carry;
            temp1 -> data = t%10;
            carry = t/10;
            prev = temp1;
            temp1 = temp1 -> next;
        }
        
        if(carry != 0){
            prev -> next = new Node(carry);
        }
        
        return reverseLL(first);
    }
};

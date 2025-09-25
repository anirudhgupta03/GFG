/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        // code here
        if(pos == 1){
            Node* root = new Node(val);
            root -> next = head;
            return root;
        }
        
        int cnt = 1;
        Node* curr = head, *pre = NULL;
        while(curr != NULL){
            cnt++;
            pre = curr;
            curr = curr -> next;
            if(cnt == pos){
                Node* node = new Node(val);
                pre -> next = node;
                node -> next = curr;
                break;
            }
        }
        return head;
    }
};

//Ref: https://www.youtube.com/watch?v=ykelywHJWLg&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=25
/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/
class Solution {
  public:
    Node* merge(Node* n1, Node* n2){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        while(n1 != NULL && n2 != NULL){
            if(n1 -> data < n2 -> data){
                Node* nextNode = n1 -> bottom;
                temp -> bottom = n1;
                n1 = nextNode;
                temp = temp -> bottom;
            }
            else{
                Node* nextNode = n2 -> bottom;
                temp -> bottom = n2;
                n2 = nextNode;
                temp = temp -> bottom;
            }
        }
        if(n1) temp -> bottom = n1;
        if(n2) temp -> bottom = n2;
        return dummy -> bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(root == NULL || root -> next == NULL){
            return root;
        }
        Node* mergedHead = flatten(root -> next);
        root = merge(root, mergedHead);
        return root;
    }
};

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        if(head == NULL || head -> next == NULL){
            return {};
        }
        vector<pair<int,int>> res;
        Node* ptr1 = head, *ptr2 = head;
        while(ptr2 -> next != NULL) ptr2 = ptr2 -> next;
        while(ptr1 != ptr2 && (ptr1 -> prev != ptr2)){
            int sum = ptr1 -> data + ptr2 -> data;
            if(sum == target){
                res.push_back({ptr1 -> data, ptr2 -> data});
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> prev;
            }
            else if(sum > target){
                ptr2 = ptr2 -> prev;
            }
            else{
                ptr1 = ptr1 -> next;
            }
        }
        return res;
    }
};

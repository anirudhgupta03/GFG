//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x)
{
    stack<Node*> l, r;
    
    while(root1){
        l.push(root1);
        root1 = root1 -> left;
    }
    
    while(root2){
        r.push(root2);
        root2 = root2 -> right;
    }
    
    int count = 0;
    
    while(!l.empty() && !r.empty()){
        
        Node* curr1 = l.top(), *curr2 = r.top();
        int a = curr1 -> data, b = curr2 -> data;
        
        if(a + b < x){
            l.pop();
            curr1 = curr1 -> right;
            while(curr1){
                l.push(curr1);
                curr1 = curr1 -> left;
            }
        }
        else if(a + b > x){
            r.pop();
            curr2 = curr2 -> left;
            while(curr2){
                r.push(curr2);
                curr2 = curr2 -> right;
            }
        }
        else{
            count++;
            l.pop();
            r.pop();
            curr1 = curr1 -> right;
            while(curr1){
                l.push(curr1);
                curr1 = curr1 -> left;
            }
            curr2 = curr2 -> left;
            while(curr2){
                r.push(curr2);
                curr2 = curr2 ->right;
            }
        }
    }
    
    return count;
}

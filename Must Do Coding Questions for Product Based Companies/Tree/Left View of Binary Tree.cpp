/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   
   vector<int> res;
   if(root == NULL){
       return res;
   }
   
   queue<Node*> q;
   q.push(root);
  
   while(!q.empty()){
       
       int sz = q.size();
       bool flag = true;
       while(sz--){
           Node* curr = q.front();
           q.pop();
           
           if(flag){
               res.push_back(curr -> data);
               flag = false;
           }
           if(curr -> left) q.push(curr -> left);
           if(curr -> right) q.push(curr -> right);
       }
   }
   return res;
}

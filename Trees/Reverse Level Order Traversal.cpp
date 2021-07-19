/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
   vector<int> res;
   
   if(root == NULL){
       return res;
   }
   
   queue<Node*> q;
   q.push(root);
   
  while(!q.empty()){
       int sz = q.size();
       while(sz--){
           
           Node* curr = q.front();
           q.pop();
           
           res.push_back(curr -> data);
           
           if(curr -> right) q.push(curr -> right);
           if(curr -> left) q.push(curr -> left);
       }
   }
   reverse(res.begin(),res.end());
   return res;
}

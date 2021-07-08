
class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       
       while(!q.empty()){
           
           int sz = q.size();
           while(sz--){
               
               Node* curr = q.front();
               q.pop();
               
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
               
               if(sz == 0){
                   curr->nextRight = NULL;
                   continue;
               }
               
               curr->nextRight = q.front();
           }
       }
    }    
      
};

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        if(root == NULL){
            return true;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            int temp = sz, count = 0;
            while(sz--){
               
               Node* curr = q.front();
               q.pop();
               
               if(curr -> left == NULL && curr -> right == NULL){
                   count++;
               }
               if(curr -> left) q.push(curr -> left);
               if(curr -> right) q.push(curr -> right);
            }
            if(!(count == 0 || count == temp)){
                return false;
            }
        }
        return true;
    }
};

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root, vector<int> &temp){
        
        stack<Node*> s;
        
        while(root){
            s.push(root);
            root = root -> left;
        }
        
        while(!s.empty()){
            Node* curr = s.top();
            s.pop();
            
            temp.push_back(curr->data);
            curr = curr -> right;
            while(curr){
                s.push(curr);
                curr = curr -> left;
            }
        }
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> temp1, temp2;
       
       inorder(root1,temp1);
       inorder(root2,temp2);
       
       int p1 = 0, p2 = 0;
       
       vector<int> temp;
       
       while(p1 < temp1.size() && p2 < temp2.size()){
           
           if(temp1[p1] < temp2[p2]){
               temp.push_back(temp1[p1]);
               p1++;
           }
           else{
               temp.push_back(temp2[p2]);
               p2++;
           }
       }
       
       while(p1 < temp1.size()){
           temp.push_back(temp1[p1]);
           p1++;
       }
       
       while(p2 < temp2.size()){
           temp.push_back(temp2[p2]);
           p2++;
       }
       
       return temp;
    }

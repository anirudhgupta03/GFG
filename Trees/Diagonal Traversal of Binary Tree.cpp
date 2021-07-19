/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   vector<int> res;
   
   if(root == NULL){
       return res;
   }
   stack<pair<Node*,int>> st;
   
   map<int,vector<int>> mp;
   
   st.push({root,0});
   
   while(!st.empty()){
       
       Node* curr = st.top().first;
       int d = st.top().second;
       st.pop();
       
       mp[d].push_back(curr -> data);
       if(curr -> right) st.push({curr -> right,d});
       if(curr -> left) st.push({curr -> left,d+1});
   }
   vector<int> temp;
   for(auto x: mp){
       temp = x.second;
       for(int i = 0; i < temp.size(); i++){
           res.push_back(temp[i]);
       }
   }
   return res;
}

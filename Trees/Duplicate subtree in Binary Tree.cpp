//Ref: https://www.youtube.com/watch?v=_j7yb_nWFO8
class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    string solve(Node* root, unordered_map<string,int> &m){
        if(root == NULL) return "$";
        string s = "";
        if(root -> left == NULL && root -> right == NULL){
            s = to_string(root -> data);
            return s;
        }
        s = s + to_string(root -> data);
        s.push_back(' ');
        s = s + solve(root -> left, m);
        s.push_back(' ');
        s = s + solve(root -> right, m);
        m[s]++;
        return s;
    }
    int dupSub(Node *root) {
         unordered_map<string,int> m;
         solve(root,m);
         for(auto x: m){
             if(x.second >= 2) return 1;
         }
         return 0;
    }
}

//Alter
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    string check(Node* root, unordered_map<string,int> &umap, bool &flag){
        
        if(root == NULL){
            return "";
        }
        
        if(root -> left == NULL && root -> right == NULL){
            return to_string(root -> data);
        }
        
        string l = check(root -> left, umap, flag);
        string r = check(root -> right, umap, flag);
        
        string temp = l + " " + to_string(root -> data) + " " + r;
        
        if(umap.find(temp) != umap.end()){
            flag = true;
        }
        else{
            umap[temp]++;
        }
        
        return temp;
    }
    int dupSub(Node *root) {
        
        if(root == NULL){
            return 0;
        }
        
        unordered_map<string,int> umap;
        bool flag = false;
        check(root, umap, flag);
        
        return flag;
    }
};

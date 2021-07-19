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

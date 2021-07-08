class Solution{
    public:
    Node* solve(int &ind, int l, int r, int pre[], int in[]){
        
        if(l > r){
            return NULL;
        }
        int j;
        for(int i = l; i <= r; i++){
            if(pre[ind] == in[i]){
                j = i;
                break;
            }
        }
        Node* root = new Node(pre[ind]);
        ind++;
        root -> left = solve(ind,l,j-1,pre,in);
        root -> right = solve(ind,j+1,r,pre,in);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int ind = 0;
        return solve(ind,0,n-1,pre,in);
    }
};

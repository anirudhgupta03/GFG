class Solution
{
	public:
	    struct node{
	        int freq;
	        char c;
	        node* left, *right;
	    };
	    struct mycomp{
	        bool operator()(node* a, node* b){
	            return a->freq > b->freq;
	        }
	    };
	    void preorder(node* root, string code, vector<string> &res){
	        
	        if(root == NULL){
	            return;
	        }
	        if(root -> c != '*'){
	            res.push_back(code);
	            return;
	        }
	        
	        preorder(root->left,code+'0',res);
	        preorder(root->right,code+'1',res);
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<node*, vector<node*>,mycomp> pq;
		    
		    for(int i = 0; i < N; i++){
		        
		        node* x = (struct node*)malloc(sizeof(struct node));
		        
		        x -> c = S[i];
		        x -> freq = f[i];
		        x -> left = NULL;
		        x -> right = NULL;
		        pq.push(x);
		    }
		    
		    while(pq.size() != 1){
		        node* a = pq.top();
		        pq.pop();
		        node* b = pq.top();
		        pq.pop();
		        
		        node* x = (struct node*)malloc(sizeof(struct node));
		        x -> c = '*';
		        x -> freq = a -> freq + b -> freq;
		        x -> left = a;
		        x -> right = b;
		        pq.push(x);
		    }
		    node* root = pq.top();
		    
		    vector<string> res;
		    string code;
		    
		    preorder(root,code,res);
		    
		    return res;
		}
};

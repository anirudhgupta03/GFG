class Solution{   
public:
    struct TrieNode{
        
        int count;
        TrieNode* child[2];
        
        TrieNode(){
            count = 0;
            for(int i = 0; i < 2; i++){
                child[i] = NULL;
            }
        }
    };
    void add(TrieNode* root, int num){
        
        for(int i = 31; i >= 0; i--){
            
            int bit = (num & (1 << i)) ? 1 : 0;
            
            if(root -> child[bit] == NULL){
                root -> child[bit] = new TrieNode();
            }
            root = root -> child[bit];
            root -> count++;
        }
    }
    int findMinXOR(TrieNode* root, int num){
        
        int xorsum = 0;
        
        bool flag = true;
        
        for(int i = 31; i >= 0; i--){
            
            int bit = (num & (1 << i)) ? 1 : 0;
            
            TrieNode* temp = root -> child[bit];
            
            if(temp != NULL && temp -> count > 1 && flag){   
                root = root -> child[bit];
            }
            else if(temp != NULL && !flag){         //Once we have started traversing other bits then no need to consider count
                root = root -> child[bit];
            }
            else if(root -> child[1-bit] != NULL){
                flag = false;
                root = root -> child[1-bit];
                xorsum += pow(2,i);    
            }   
        }
        return xorsum;
    }
    int minxorpair(int N, int arr[]){    
        
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < N; i++){
            add(root,arr[i]);
        }
        
        int minXOR = INT_MAX;
        
        for(int i = 0; i < N; i++){
            int tempXOR = findMinXOR(root,arr[i]);
            minXOR = min(minXOR,tempXOR);
        }
        return minXOR;
    }
};

//Ref: https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
class Solution{   
public:
    struct TrieNode{
        
        TrieNode* child[26];
        
        TrieNode(){
            for(int i = 0; i < 26; i++){
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
        }
    }
    int findMaxXOR(TrieNode* root, int num){
        
        int xorsum = 0;
        
        for(int i = 31; i >= 0; i--){
            int bit = (num & (1 << i)) ? 1 : 0;
            
            if(root -> child[1-bit] != NULL){
                xorsum += pow(2,i);
                root = root -> child[1-bit];
            }
            else{
                root = root -> child[bit];
            }
        }
        return xorsum;
    }
    int maxSubarrayXOR(int N, int arr[]){    
        
        TrieNode *root = new TrieNode();
        
        add(root,0);
        
        int currxor = 0, maxXOR = INT_MIN;
        
        for(int i = 0; i < N; i++){
            
            currxor ^= arr[i];
            add(root,currxor);
            
            maxXOR = max(maxXOR,findMaxXOR(root,currxor));
        }
        
        return maxXOR;
    }
};

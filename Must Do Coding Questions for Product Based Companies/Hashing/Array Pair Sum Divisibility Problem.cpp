//Ref: https://www.youtube.com/watch?v=BvKv-118twg
class Solution{
public:
    bool canPair(vector<int> nums, int k) {
        
        unordered_map<int,int> umap;
        
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]%k]++;
        }
        
        for(auto x: umap){
            
            int rem = x.first, cnt = x.second;
            
            if(k % 2 == 0){
                if(rem == k/2 || rem == 0){
                    if(cnt % 2 != 0){
                        return false;
                    }
                }
                else if(umap[k-rem] != umap[rem]){
                    return false;
                }
            }
            else{
                if(rem == 0){
                    if(cnt % 2 != 0){
                        return false;
                    }
                }
                else if(umap[k-rem] != umap[rem]){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution{
public:
    int woodCut(int tree[], int n, int h){
        
        int amt = 0;
        
        for(int i = 0; i < n; i++){
            amt += max(tree[i]-h,0);
        }
        
        return amt;
    }
    int find_height(int tree[], int n, int k)
    {
        int lo = 0, hi = *max_element(tree,tree+n);
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            int cut = woodCut(tree,n,mid);
            
            if(cut == k){
                return mid;
            }
            else if(cut < k){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return -1;
    }
};

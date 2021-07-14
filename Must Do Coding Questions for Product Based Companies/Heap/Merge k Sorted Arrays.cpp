class Solution
{
    public:
    //Function to merge k sorted arrays.
    #define pip pair<int,pair<int,int>>
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        
        for(int i = 0; i < K; i++){
            pq.push({arr[i][0],{i,0}});
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            
            int ele = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            
            res.push_back(ele);
            
            if(c < K - 1){
                c++;
                pq.push({arr[r][c],{r,c}});
            }
        }
        
        return res;
    }
};

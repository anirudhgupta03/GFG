class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        
        int count;
        
        vector<int> res;
        
        for(int i = coins.size() - 1; i >= 0; i--){
            
            count = N/coins[i];
            
            for(int j = 0; j < count; j++){
                res.push_back(coins[i]);
            }
            N %= coins[i];
            
            if(N == 0) break;
        }
        
        return res;
    }
};

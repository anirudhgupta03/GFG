bool cmp(pair<int,int> p1, pair<int,int> p2){
        
        double r1 = (double)(p1.first)/(p1.second);
        double r2 = (double)(p2.first)/(p2.second);
        
        return r1 > r2;
}
class Solution
{
    public:
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++){
            
            v.push_back({arr[i].value,arr[i].weight});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        double value = 0;
        
        for(int i = 0; i < n; i++){
            
            if(v[i].second <= W){
                value += v[i].first;
                W -= v[i].second;
            }
            else{
                value += ((double)W/v[i].second)*(v[i].first);
                W = 0;
            }
        }
        return value;
    }
        
};

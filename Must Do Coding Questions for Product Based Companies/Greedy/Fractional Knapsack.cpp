/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    #define ppd pair<pair<int,int>,double>
    bool static cmp(ppd &p1, ppd &p2){
        return p1.second > p2.second;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<ppd> v(n);
        
        for(int i = 0; i < n; i++){
            v[i] = {{arr[i].value, arr[i].weight},(1.0*(arr[i].value)/arr[i].weight)};
        }
        
        sort(v.begin(), v.end(), cmp);
        
        double maxValue = 0;
        
        for(int i = 0; i < n; i++){
            if(W >= v[i].first.second){
                maxValue += v[i].first.first;
                W -= v[i].first.second;
            }
            else{
                maxValue += W*v[i].second;
                break;
            }
        }
        return maxValue;
    }
        
};

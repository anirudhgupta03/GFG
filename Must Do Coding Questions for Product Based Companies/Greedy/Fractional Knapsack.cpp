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
    bool static cmp(Item item1, Item item2){
        
        double valPerWt1 = (double)item1.value/item1.weight;
        double valPerWt2 = (double)item2.value/item2.weight;
        return valPerWt1 > valPerWt2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        
        double maxValue = 0;
        
        for(int i = 0; i < n; i++){
            if(W >= arr[i].weight){
                maxValue += arr[i].value;
                W -= arr[i].weight;
            }
            else{
                maxValue += W*((double)arr[i].value/arr[i].weight);
                break;
            }
        }
        return maxValue;
    } 
};

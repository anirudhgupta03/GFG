#define ll long long
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        if(n == 1){
            return 0;
        }
        ll totalcost = 0;
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        for(ll i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        while(pq.size() != 1){
            
            ll rope1 = pq.top();
            pq.pop();
            ll rope2 = pq.top();
            pq.pop();
            
            totalcost += rope1 + rope2;
            
            pq.push(rope1+rope2);
        }
        
        return totalcost;
    }
};

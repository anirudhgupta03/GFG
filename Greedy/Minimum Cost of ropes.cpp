class Solution
{
    #define ll long long
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        sort(arr,arr+n);
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        for(ll i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        ll cost = 0;
        while(pq.size() != 1){
            
            ll rope1 = pq.top();
            pq.pop();
            ll rope2 = pq.top();
            pq.pop();
            
            cost += rope1 + rope2;
            pq.push(rope1+rope2);
        }
        
        return cost;
    }
};

class Solution{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans;
       ans.push_back(1);
       
       stack<int> s;
       s.push(0);
       
       int count;
       
       for(int i = 1; i < n; i++){
           
           if(price[i] < price[s.top()]){
               ans.push_back(1);
           }
           else{
               count = 1;
               while(!s.empty() && price[s.top()] <= price[i]){
                   count += ans[s.top()];
                   s.pop();
               }
               
               ans.push_back(count);
           }
           s.push(i);
       }
       
       return ans;
    }
};

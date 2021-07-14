class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> res(n);
       
       res[0] = 1;
       
       stack<int> st;
       st.push(0);
       
       for(int i = 1; i < n; i++){
           
           if(price[st.top()] > price[i]){
               res[i] = i - st.top();
           }
           else{
               while(!st.empty() && price[st.top()] <= price[i]){
                   st.pop();
               }
               
               if(st.empty()){
                   res[i] = i + 1;
               }
               else{
                   res[i] =  i - st.top();
               }
           }
           st.push(i);
       }
       
       return res;
    }
};

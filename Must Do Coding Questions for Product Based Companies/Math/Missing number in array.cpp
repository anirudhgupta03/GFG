class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
       
       long long sum = 0;
       
       for(auto x: array){
           sum += x;
       }
       
       return n*(n+1)/2 - sum;
    }
};

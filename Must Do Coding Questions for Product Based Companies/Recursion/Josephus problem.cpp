class Solution
{
    public:
    int josephus(int n, int k)
    {
       vector<int> v(n);
       for(int i = 1; i <= n; i++){
           v[i-1] = i;
       }
       
       int s = 0;
       
       while(v.size() != 1){
           
           s = (s + k - 1)%v.size();
           v.erase(v.begin() + s);
       }
       
       
       return v[0];
    }
};

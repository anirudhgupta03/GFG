//Ref: https://www.youtube.com/watch?v=1RpMc3fv0y4
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> lis;
       lis.push_back(a[0]);
       
       for(int i = 1; i < n; i++){
           
           if(a[i] > lis.back()){
               lis.push_back(a[i]);
           }
           else{
               int ind = lower_bound(lis.begin(),lis.end(),a[i]) - lis.begin();
               lis[ind] = a[i];
           }
       }
       return lis.size();
    }
};

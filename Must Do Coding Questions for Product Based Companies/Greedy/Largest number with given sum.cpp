class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        if(sum > 9*n){
            return "-1";
        }
        
        string res;
        
        for(int i = 1; i <= sum/9; i++){
            res.push_back('9');
        }
        sum -= (sum/9)*9;
        if(res.size() == n){
            return res;
        }
        
        res.push_back(sum + '0');
        
        while(res.size() != n){
            res.push_back('0');
        }
        return res;
    }
};

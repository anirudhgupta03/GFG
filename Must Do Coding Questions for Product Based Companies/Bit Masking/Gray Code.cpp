class Solution
{
    public:
    vector<string> graycode(int n)
    {
        vector<string> res;
        
        res.push_back("0");
        res.push_back("1");
        
        vector<string> temp;
        
        for(int i = 2; i <= n; i++){
            
            temp = res;
            
            for(int j = 0; j < res.size(); j++){
                res[j] = "0" + temp[j];
            }
            
            for(int j = res.size() - 1; j >= 0; j--){
                res.push_back("1" + temp[j]);
            }
        }
        return res;
    }
};

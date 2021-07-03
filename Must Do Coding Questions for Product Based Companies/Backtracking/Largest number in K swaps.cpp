class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int ind, string &str, int count, int k, string &ans){
        
        if(count <= k){
            if(str > ans){
                ans = str;
            }
            if(count == k)
            return;
        }
        
        if(ind == str.size()){
            return;
        }
        
        char maxm = str[ind];
        
        for(int j = ind + 1; j < str.size(); j++){
            if(str[j] > maxm){
                maxm = str[j];
            }
        }
        
        if(maxm != str[ind]){
            count++;
        }
        
        for(int j = ind; j < str.size(); j++){
            
            if(str[j] == maxm){
                  swap(str[ind],str[j]);
                  solve(ind+1,str,count,k,ans);
                  swap(str[ind],str[j]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string ans;
       int count = 0;
       solve(0,str,count,k,ans);
       
       return ans;
    }
};

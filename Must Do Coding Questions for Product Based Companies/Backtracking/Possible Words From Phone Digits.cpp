class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int ind, vector<string> &res, string &temp, int a[], int N, unordered_map<int,string> &umap){
        
        if(ind == N){
            res.push_back(temp);
            return;
        }
        
        for(int j = 0; j < umap[a[ind]].size(); j++){
            temp.push_back(umap[a[ind]][j]);
            solve(ind+1,res,temp,a,N,umap);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        unordered_map<int,string> umap;
        umap[2] = "abc";
        umap[3] = "def";
        umap[4] = "ghi";
        umap[5] = "jkl";
        umap[6] = "mno";
        umap[7] = "pqrs";
        umap[8] = "tuv";
        umap[9] = "wxyz";
        
        vector<string> res;
        string temp;
        
        solve(0,res,temp,a,N,umap);
        
        return res;
    }
};

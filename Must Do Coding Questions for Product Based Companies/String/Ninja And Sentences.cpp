//https://www.codingninjas.com/codestudio/problems/ninja-and-sentences_1123512?leftPanelTab=0
void solve(int ind, vector<vector<string>> &arr, vector<vector<string>> &ans, vector<string> &temp){
    
    if(ind == arr.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < arr[ind].size(); i++){
        temp.push_back(arr[ind][i]);
        solve(ind + 1, arr, ans, temp);
        temp.pop_back();
    }
}
void createSentences(vector < vector < string > > & arr, vector < vector < string > > & ans) {
    vector<string> temp;
    solve(0, arr, ans, temp);
}

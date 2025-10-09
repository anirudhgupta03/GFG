class Solution {
  public:
    void generateBinaryStrings(int ind, string s, vector<string> &res, int n){
        if(ind == n){
            res.push_back(s);
            return;
        }
        generateBinaryStrings(ind + 1, s + "0", res, n);
        generateBinaryStrings(ind + 1, s + "1", res, n);
    }
    vector<string> binstr(int n) {
        // code here
        vector<string> res;
        generateBinaryStrings(0, "", res, n);
        return res;
    }
};

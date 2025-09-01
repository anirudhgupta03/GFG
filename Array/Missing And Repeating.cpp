class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            int eleInd = abs(arr[i]) - 1;
            if(arr[eleInd] < 0){
                res.push_back(abs(arr[i]));
            }
            else{
                arr[eleInd] = -1*(abs(arr[eleInd]));
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

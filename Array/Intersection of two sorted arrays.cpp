class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int> res;
        int m = arr1.size(), n = arr2.size();
        int i = 0, j = 0;
        
        while(i < m && j < n){
            if(arr1[i] == arr2[j]){
                int ele = arr1[i];
                res.push_back(arr1[i]);
                while(i < m && arr1[i] == ele) i++;
                while(j < n && arr2[j] == ele) j++;
            }
            else if(arr1[i] < arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};

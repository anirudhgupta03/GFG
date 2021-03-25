class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        sort(arr.begin(),arr.end());
        int count = 0;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(K >= arr[i]){
                count++;
                K -= arr[i];
            }
        }
        return count;
    }
};

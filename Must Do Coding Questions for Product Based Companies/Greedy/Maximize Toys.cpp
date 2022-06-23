class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        
        int toys = 0;
        
        for(int i = 0; i < N; i++){
            if(arr[i] <= K){
                toys++;
                K -= arr[i];
            }
            else{
                break;
            }
        }
        return toys;
    }
};

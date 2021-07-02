//Ref: https://www.geeksforgeeks.org/count-number-of-triplets-in-an-array-having-sum-in-the-range-a-b/
class Solution {
  public:
    int countTriplets(int Arr[], int N, int L, int R) {
        
        sort(Arr,Arr + N);
        
        int count1 = 0, count2 = 0;
        
        for(int i = 0; i <= N - 2; i++){
            
            int l = i + 1, r = N - 1;
            
            while(l < r){
                
                int t = Arr[i] + Arr[l] + Arr[r];
                
                if(t <= R){
                    count1 += r-l;
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        
        for(int i = 0; i <= N - 2; i++){
            
            int l = i + 1, r = N - 1;
            
            while(l < r){
                
                int t = Arr[i] + Arr[l] + Arr[r];
                
                if(t < L){
                    count2 += r-l;
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return count1 - count2;
    }
};

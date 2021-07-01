//Time Complexity - O(N)
//Space Complexity - O(1)
class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        
        int carry = 1;
        
        for(int i = N - 1; i >= 0; i--){
            
            int temp = arr[i] + carry;
            
            arr[i] = temp%10;
            carry = temp/10;
        }
        
        if(carry != 0){
            arr.insert(arr.begin(),carry);
        }
        
        return arr;
    }
};
